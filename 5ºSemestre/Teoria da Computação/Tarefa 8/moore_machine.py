"""
Aula 09 – Autômatos com Saída
Implementação: Máquina de Moore

Exemplo: Detector de Paridade de 'a's
--------------------------------------
A máquina lê uma string sobre o alfabeto {a, b} e produz uma
saída em cada estado indicando se o número de 'a's lidos até
o momento é PAR ('P') ou ÍMPAR ('I').

Definição formal:
  - Estados (Q)         : {q_par, q_impar}
  - Alfabeto de entrada : {a, b}
  - Alfabeto de saída   : {P, I}
  - Estado inicial      : q_par  (0 'a's → par)
  - Função de transição (δ):
        δ(q_par,   a) = q_impar
        δ(q_par,   b) = q_par
        δ(q_impar, a) = q_par
        δ(q_impar, b) = q_impar
  - Função de saída (λ) — associada aos ESTADOS:
        λ(q_par)   = 'P'
        λ(q_impar) = 'I'

Diagrama:
                  a                   a
         ┌────────────────┐  ┌────────────────┐
         │                ▼  │                ▼
      ──►[q_par / P] ───────► [q_impar / I]
              ▲    a               │
              └────────────────────┘
         b (auto-loop em cada estado)

Observação: na Máquina de Moore a saída é emitida ao ENTRAR
num estado, por isso o output tem comprimento |entrada| + 1
(inclui a saída do estado inicial antes de qualquer leitura).
"""

from automata.fa.Moore import Moore

# 1. Definição da Máquina de Moore
moore = Moore(
    # Estados
    ['q_par', 'q_impar'],

    # Alfabeto de entrada
    ['a', 'b'],

    # Alfabeto de saída
    ['P', 'I'],

    # Função de transição δ : Q × Σ → Q
    {
        'q_par': {
            'a': 'q_impar',   # leu 'a' → passa a ímpar
            'b': 'q_par',     # leu 'b' → permanece par
        },
        'q_impar': {
            'a': 'q_par',     # leu 'a' → volta a par
            'b': 'q_impar',   # leu 'b' → permanece ímpar
        },
    },

    # Estado inicial
    'q_par',

    # Função de saída λ : Q → O  (saída associada a cada estado)
    {
        'q_par':   'P',   # Par    → emite 'P'
        'q_impar': 'I',   # Ímpar  → emite 'I'
    }
)

# 2. Exibição da definição da máquina
print("=" * 55)
print(moore)
print("=" * 55)

# 3. Testes com entradas de exemplo
test_inputs = [
    ('a',     "1 'a'  → 1 ímpar → termina em I"),
    ('aa',    "2 'a's → 2 par   → termina em P"),
    ('ab',    "'a' depois 'b'   → termina em I"),
    ('aba',   "2 'a's + 'b'     → termina em P"),
    ('bbbb',  "só 'b's, 0 'a's  → sempre P"),
    ('aabba', "3 'a's           → termina em I"),
    ('abbba', "mesma da apostila"),
]

print("\n{:<10} {:<18} {}".format("Entrada", "Saída", "Observação"))
print("-" * 55)
for entrada, obs in test_inputs:
    saida = moore.get_output_from_string(entrada)
    print(f"'{entrada:<8}' → '{saida:<16}' {obs}")

# 4. Conversão para Máquina de Mealy equivalente
print("\n" + "=" * 55)
print("Conversão automática para Máquina de Mealy equivalente:")
print("=" * 55)
moore.convert_to_mealy()
