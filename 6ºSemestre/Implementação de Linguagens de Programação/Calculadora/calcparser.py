# calcparser.py
# Parser para uma calculadora com operações aritméticas e lógicas.
# Usa os tokens definidos em calclex.py
import ply.yacc as yacc

# Os tokens precisam ser importados do analisador léxico
from calclex import tokens, lexer

# Precedência (da MENOR para a MAIOR):
#   ||  <  &&  <  + -  <  * /  <  ! e menos unário
precedence = (
    ('left', 'OR'),
    ('left', 'AND'),
    ('left', 'PLUS', 'MINUS'),
    ('left', 'TIMES', 'DIVIDE'),
    ('right', 'NOT', 'UMINUS'),
)

# Dicionário de variáveis (identificadores)
names = {}


def p_statement_assign(p):
    'statement : ID EQUALS expression'
    names[p[1]] = p[3]
    p[0] = p[3]


def p_statement_expr(p):
    'statement : expression'
    print(p[1])
    p[0] = p[1]


# operações aritméticas
def p_expression_binop(p):
    '''expression : expression PLUS expression
                  | expression MINUS expression
                  | expression TIMES expression
                  | expression DIVIDE expression'''
    if p[2] == '+':
        p[0] = p[1] + p[3]
    elif p[2] == '-':
        p[0] = p[1] - p[3]
    elif p[2] == '*':
        p[0] = p[1] * p[3]
    elif p[2] == '/':
        if p[3] == 0:
            print("Erro: divisão por zero")
            p[0] = 0
        else:
            p[0] = p[1] / p[3]


# operações lógicas
def p_expression_and(p):
    'expression : expression AND expression'
    p[0] = bool(p[1]) and bool(p[3])


def p_expression_or(p):
    'expression : expression OR expression'
    p[0] = bool(p[1]) or bool(p[3])


def p_expression_not(p):
    'expression : NOT expression'
    p[0] = not bool(p[2])


# demais regras
def p_expression_uminus(p):
    'expression : MINUS expression %prec UMINUS'
    p[0] = -p[2]


def p_expression_group(p):
    'expression : LPAREN expression RPAREN'
    p[0] = p[2]


def p_expression_number(p):
    'expression : NUMBER'
    p[0] = p[1]


def p_expression_name(p):
    'expression : ID'
    try:
        p[0] = names[p[1]]
    except LookupError:
        print("Identificador indefinido '%s'" % p[1])
        p[0] = 0


def p_error(p):
    if p:
        print("Erro de sintaxe em '%s'" % p.value)
    else:
        print("Erro de sintaxe no fim da entrada")


parser = yacc.yacc()

if __name__ == "__main__":
    while True:
        try:
            s = input('calc > ')
        except EOFError:
            break
        if not s.strip():
            continue
        parser.parse(s, lexer=lexer)
