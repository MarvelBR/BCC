# Ex5: Considere Σ = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} e defina autômatos finitos determinísticos para as seguintes linguagens:
# AFD 𝑀8 que reconheça 𝐿8 = {𝑥 ∈ Σ^∗ ∣ 𝑥 mod 2 = 0}

from automata.fa.dfa import DFA

# Definindo o AFD
dfa = DFA(
    states={'q0', 'q_even', 'q_odd'},
    input_symbols={'0','1','2','3','4','5','6','7','8','9'},
    transitions={
        'q0': {
            '0': 'q_even', '1': 'q_odd', '2': 'q_even', '3': 'q_odd',
            '4': 'q_even', '5': 'q_odd', '6': 'q_even', '7': 'q_odd',
            '8': 'q_even', '9': 'q_odd'
        },
        'q_even': {
            '0': 'q_even', '1': 'q_odd', '2': 'q_even', '3': 'q_odd',
            '4': 'q_even', '5': 'q_odd', '6': 'q_even', '7': 'q_odd',
            '8': 'q_even', '9': 'q_odd'
        },
        'q_odd': {
            '0': 'q_even', '1': 'q_odd', '2': 'q_even', '3': 'q_odd',
            '4': 'q_even', '5': 'q_odd', '6': 'q_even', '7': 'q_odd',
            '8': 'q_even', '9': 'q_odd'
        }
    },
    initial_state='q0',
    final_states={'q_even'}
)

testes = ["123", "246", "135", "0", "9998"]

for t in testes:
    print(f"{t} ->", dfa.accepts_input(t))