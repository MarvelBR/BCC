"""
Aula 09 – Autômatos com Saída
Implementação: Máquina de Mealy

Exemplo: Detector de Mudança em Sequência Binária
--------------------------------------------------
A máquina lê uma string sobre o alfabeto {0, 1} e emite
para cada símbolo lido:
  - 'M' se houve MUDANÇA em relação ao símbolo anterior
  - 'I' se o símbolo foi IGUAL ao anterior

Essa máquina é útil, por exemplo, em comunicação digital
para detectar transições de sinal (borda de subida/descida).

Definição formal:
  - Estados (Q)         : {q0, q1}
      q0 = o último símbolo lido foi '0' (ou estado inicial)
      q1 = o último símbolo lido foi '1'
  - Alfabeto de entrada : {0, 1}
  - Alfabeto de saída   : {M, I}
  - Estado inicial      : q0
  - Função de transição + saída (δ, λ) — par (próx. estado, saída):

         Estado atual │  Entrada '0'      │  Entrada '1'
        ──────────────┼───────────────────┼──────────────────
              q0      │  (q0, 'I')        │  (q1, 'M')
              q1      │  (q0, 'M')        │  (q1, 'I')

Diagrama:
                    0 / I                 1 / I
              ┌─────────────┐       ┌──────────────┐
              │             ▼       │              ▼
           ──►[  q0  ] ──────────► [  q1  ]
                        1 / M       ◄──────
                                    0 / M

Observação: na Máquina de Mealy a saída é emitida em cada
TRANSIÇÃO, portanto o comprimento da saída é igual ao da entrada.
"""

from automata.fa.Mealy import Mealy

# 1. Definição da Máquina de Mealy
mealy = Mealy(
    # Estados
    ['q0', 'q1'],

    # Alfabeto de entrada
    ['0', '1'],

    # Alfabeto de saída
    ['M', 'I'],

    # Função de transição + saída  δ : Q × Σ → Q × O
    # Formato: { estado: { símbolo: (próximo_estado, saída) } }
    {
        'q0': {
            '0': ('q0', 'I'),   # estava em '0', leu '0' → Igual,   vai p/ q0
            '1': ('q1', 'M'),   # estava em '0', leu '1' → Mudança, vai p/ q1
        },
        'q1': {
            '0': ('q0', 'M'),   # estava em '1', leu '0' → Mudança, vai p/ q0
            '1': ('q1', 'I'),   # estava em '1', leu '1' → Igual,   vai p/ q1
        },
    },

    # Estado inicial
    'q0'
)

# 2. Exibição da definição da máquina
print("=" * 60)
print(mealy)
print("=" * 60)

# 3. Testes com entradas de exemplo
test_inputs = [
    ('0000', "nenhuma mudança → tudo Igual"),
    ('1111', "nenhuma mudança → tudo Igual"),
    ('0101', "alterna sempre  → tudo Mudança"),
    ('0011', "1 mudança no meio"),
    ('0110', "muda, fica, muda"),
    ('10110010', "sinal variado"),
]

print("\n{:<12} {:<14} {}".format("Entrada", "Saída", "Observação"))
print("-" * 60)
for entrada, obs in test_inputs:
    saida = mealy.get_output_from_string(entrada)
    print(f"'{entrada:<10}' → '{saida:<12}' {obs}")

# 4. Conversão para Máquina de Moore equivalente
print("\n" + "=" * 60)
print("Conversão automática para Máquina de Moore equivalente:")
print("=" * 60)
mealy.convert_to_moore()
