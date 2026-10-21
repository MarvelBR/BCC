# Analisador léxico para uma calculadora com números, identificadores,
# operadores aritméticos (+, -, *, /) e operadores lógicos (&&, ||, !)
import ply.lex as lex

# Lista de tokens (obrigatória)
tokens = (
    'NUMBER',
    'ID',
    'PLUS',
    'MINUS',
    'TIMES',
    'DIVIDE',
    'LPAREN',
    'RPAREN',
    'AND',
    'OR',
    'NOT',
    'EQUALS',   # usado pelo parser para atribuição (a = 3 + 4)
)

# Regras para tokens simples
t_PLUS   = r'\+'
t_MINUS  = r'-'
t_TIMES  = r'\*'
t_DIVIDE = r'/'
t_LPAREN = r'\('
t_RPAREN = r'\)'
t_AND    = r'&&'
t_OR     = r'\|\|'
t_NOT    = r'!'
t_EQUALS = r'='


def t_NUMBER(t):
    r'\d+'
    t.value = int(t.value)
    return t


def t_ID(t):
    r'[a-zA-Z_][a-zA-Z0-9_]*'
    return t


# Contagem de linhas
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)


# Caracteres ignorados (espaços e tabs)
t_ignore = ' \t'


# Tratamento de erro
def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)


# Constrói o lexer
lexer = lex.lex()

if __name__ == "__main__":
    data = '''
    a && b || a + b
    !c
    (x + 1) * y - 2
    '''
    lexer.input(data)
    while True:
        tok = lexer.token()
        if not tok:
            break
        print(tok)
