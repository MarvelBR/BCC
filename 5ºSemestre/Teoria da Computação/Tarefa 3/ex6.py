# Ex6: Considere Σ = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} e defina autômatos finitos determinísticos para as seguintes linguagens:
# 6. AFD 𝑀9 que reconheça 𝐿9 = {𝑥 ∈ Σ^∗ ∣ 𝑥 mod 5 = 0}

from automata.fa.dfa import DFA

# Definindo o AFD
dfa = DFA(
    states={'q0', 'q1', 'q2'},
    input_symbols={'0','1','2','3','4','5','6','7','8','9'},
    transitions={
        'q0': {
            '0': 'q1', '1': 'q2', '2': 'q2', '3': 'q2',
            '4': 'q2', '5': 'q1', '6': 'q2', '7': 'q2',
            '8': 'q2', '9': 'q2'
        },
        'q1': {
            '0': 'q1', '1': 'q2', '2': 'q2', '3': 'q2',
            '4': 'q2', '5': 'q1', '6': 'q2', '7': 'q2',
            '8': 'q2', '9': 'q2'
        },
        'q2': {
            '0': 'q1', '1': 'q2', '2': 'q2', '3': 'q2',
            '4': 'q2', '5': 'q1', '6': 'q2', '7': 'q2',
            '8': 'q2', '9': 'q2'
        }
    },
    initial_state='q0',
    final_states={'q1'}
)

testes = ["123", "246", "135", "0", "9998"]

for t in testes:
    print(f"{t} ->", dfa.accepts_input(t))