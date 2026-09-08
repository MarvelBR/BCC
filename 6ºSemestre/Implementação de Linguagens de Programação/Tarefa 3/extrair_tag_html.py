"""
Extrai o conteudo de uma tag HTML de um arquivo baixado com wget/curl,
usando expressoes regulares (modulo re do Python).

Uso:
    python3 extrair_tag_html.py <arquivo.html> <tag>

Exemplo:
    python3 extrair_tag_html.py Portal_do_Aluno.html title
"""

import re
import sys


def extract_tag(html: str, tag: str):
    """Retorna todas as ocorrencias do conteudo de <tag>...</tag> no HTML."""
    # (?is) -> i: case-insensitive (<TITLE> ou <title>)
    #          s: sem o s o regex ia parar no primeiro \n, ou seja, com s, o "." vira "qualquer caractere, incluindo quebra de linha"
    # \b: sem o \b, a regex <title também bateria com o começo de uma tag chamada <titlebar> e etc. O \b diz que termina ali
    # [^>]* : significa "consuma tudo que vier depois do nome da tag, até achar o > que fecha a tag" - feito para apagar class= id=
    # .*? -> "preguicoso" (non-greedy): para no primeiro </tag> encontrado,
    # em vez de ir ate o ULTIMO </tag> do arquivo inteiro
    padrao = rf'(?is)<{tag}\b[^>]*>(.*?)</{tag}>'
    return [m.strip() for m in re.findall(padrao, html)]


def main():
    if len(sys.argv) != 3:
        print(f"Uso: {sys.argv[0]} <arquivo.html> <tag>")
        sys.exit(1)

    caminho, tag = sys.argv[1], sys.argv[2]

    with open(caminho, encoding="utf-8", errors="ignore") as f:
        html = f.read()

    ocorrencias = extract_tag(html, tag)

    print(f"Arquivo analisado: {caminho}")
    print(f"Tag procurada: <{tag}>")
    print(f"Ocorrencias encontradas: {len(ocorrencias)}\n")

    for i, conteudo in enumerate(ocorrencias, start=1):
        # remove sub-tags HTML internas para exibir so o texto, quando fizer sentido
        texto_limpo = re.sub(r"(?is)<[^>]+>", " ", conteudo).strip()
        texto_limpo = re.sub(r"\s+", " ", texto_limpo)
        print(f"[{i}] {texto_limpo[:200]}")

    if tag.lower() == "title" and ocorrencias:
        print("\nObs.: o HTML pode conter varias tags <title>, pois icones SVG")
        print("tambem usam <title> para acessibilidade. O titulo REAL da pagina")
        print("e sempre o primeiro <title>, dentro do <head> do documento:")
        texto_primeiro = re.sub(r"(?is)<[^>]+>", " ", ocorrencias[0]).strip()
        print(f"  -> {texto_primeiro}")


if __name__ == "__main__":
    main()
