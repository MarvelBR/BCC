"""
Tarefa:
    Ler o arquivo "e-mails.txt" (lista de contatos no formato
    "NOME" <email>,) e usar Expressões Regulares (módulo `re` do Python)
    para recuperar somente os e-mails dos ALUNOS da turma, descartando
    o(s) contato(s) de professor(es).

Formato de cada linha do arquivo de entrada:
    "NOME COMPLETO" <endereco@dominio.com>,

Como funciona:
    1) Uma regex captura, em grupos separados, o NOME (entre aspas) e o
       E-MAIL (entre os sinais < >).
    2) Como o único critério textual disponível para diferenciar aluno
       de professor é o prefixo "Prof." no campo do nome, usamos uma
       segunda regex (bem simples) para identificar e excluir as linhas
       cujo nome comece com "Prof.".

Uso:
    python3 extrair_emails.py e-mails.txt
"""

import re
import sys

# Regex principal: captura o nome entre aspas e o e-mail entre < >
# Grupo 1 -> nome
# Grupo 2 -> e-mail
ALUNOS = re.compile(
    r'"(?P<nome>[^"]+)"\s*<(?P<email>[\w.+-]+@[\w-]+(?:\.[\w-]+)+)>'
)

# Regex usada apenas para identificar contatos de professores,
# que devem ser descartados da lista de alunos.
PROFESSOR = re.compile(r'^\s*Prof\.', re.IGNORECASE)


def extrair_emails_dos_alunos(caminho_arquivo: str):
    """Lê o arquivo de e-mails e devolve uma lista de tuplas
    (nome, email) somente dos alunos (exclui professores)."""

    with open(caminho_arquivo, encoding="utf-8") as f:
        conteudo = f.read()

    alunos = []
    for nome, email in ALUNOS.findall(conteudo):
        if PROFESSOR.match(nome):
            continue  # ignora contatos de professor
        alunos.append((nome.strip(), email.strip()))

    return alunos


def main():
    caminho = sys.argv[1] if len(sys.argv) > 1 else "e-mails.txt"
    alunos = extrair_emails_dos_alunos(caminho)

    print(f"Total de e-mails de ALUNOS recuperados: {len(alunos)}\n")

    for i, (nome, email) in enumerate(alunos, start=1):
        print(f"{i:2d}. {nome:<35} -> {email}")

    print("\nEndereços de e-mail):")
    for _, email in alunos:
        print(email)


if __name__ == "__main__":
    main()