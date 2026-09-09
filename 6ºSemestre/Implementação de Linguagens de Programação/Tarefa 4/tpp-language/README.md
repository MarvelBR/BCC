# TPP Language Support (VS Code)

Extensão de **Syntax Highlighting** para a linguagem **TPP**, linguagem
didática usada na disciplina *OPT011 – Implementação de Linguagens de
Programação (Compiladores)* — UTFPR, Campo Mourão.

Construída seguindo o [Syntax Highlight Guide](https://code.visualstudio.com/api/language-extensions/syntax-highlight-guide)
da documentação oficial do VS Code, usando uma gramática **TextMate**
(`.tmLanguage.json`).

## O que é destacado

A gramática (`syntaxes/tpp.tmLanguage.json`) foi construída em cima da
BNF comentada da linguagem (`ebnf-tpp-symbols`) e reconhece:

| Categoria | Exemplos | Escopo TextMate |
|---|---|---|
| Tipos | `inteiro`, `flutuante` | `storage.type.tpp` |
| Condicional | `se`, `então`/`senão` (com ou sem acento), `fim` | `keyword.control.conditional.tpp` |
| Laço | `repita`, `até`/`ate` | `keyword.control.loop.tpp` |
| Entrada/Saída | `leia`, `escreva` | `keyword.control.io.tpp` |
| Retorno | `retorna` | `keyword.control.return.tpp` |
| Nomes de função | `fatorial(`, `escreva(` | `entity.name.function.tpp` |
| Atribuição | `:=` | `keyword.operator.assignment.tpp` |
| Relacionais | `<` `>` `=` `<>` `<=` `>=` | `keyword.operator.relational.tpp` |
| Lógicos | `&&` `\|\|` `!` | `keyword.operator.logical.tpp` |
| Aritméticos | `+` `-` `*` `/` | `keyword.operator.arithmetic.tpp` |
| Números | `10`, `3.14`, `1.5e10` (inteiro / ponto flutuante / notação científica) | `constant.numeric.*.tpp` |
| Comentários | `{ texto do comentário }` | `comment.block.tpp` |
| Identificadores | `n`, `fat`, `dividendo` | `variable.other.tpp` |
| Pontuação | `( ) [ ] , :` | `punctuation.*.tpp` |

> Os comentários em TPP usam chaves `{ ... }` (visto nos exemplos do
> professor, ex: `se n > 0 então {não calcula se n > 0}`), então a
> gramática trata `{` e `}` como delimitadores de comentário de bloco,
> não como parênteses de escopo (a linguagem não usa `{}` para blocos).

## Estrutura do pacote

```
tpp-language/
├── package.json                 # manifesto da extensão
├── language-configuration.json  # comentários, auto-fechamento de ( [ {
├── syntaxes/
│   └── tpp.tmLanguage.json      # gramática TextMate (as regras de highlight)
├── examples/                    # arquivos .tpp de teste
│   ├── fatorial.tpp
│   ├── resto.tpp
│   └── soma_vetores.tpp
└── README.md                    # este arquivo
```

## Como instalar
### Gerar um pacote `.vsix` e instalar (recomendado para compartilhar)

Requer Node.js instalado.

```bash
npm install -g @vscode/vsce
cd tpp-language
vsce package
```

Isso gera um arquivo `tpp-language-0.1.0.vsix`. Depois instale com:

```bash
code --install-extension tpp-language-0.1.0.vsix
```

Ou pela interface: `Ctrl+Shift+P` → **Extensions: Install from VSIX...**
→ selecione o arquivo `.vsix` gerado.

## Testando / depurando a gramática

O VS Code tem um inspetor de escopos embutido, ótimo para conferir se
um token está caindo na categoria certa:

`Ctrl+Shift+P` → **Developer: Inspect Editor Tokens and Scopes**

Clique em qualquer palavra do seu `.tpp` aberto e ele mostra o escopo
TextMate atribuído (ex: `keyword.control.conditional.tpp`) e qual regra
da gramática gerou aquele highlight — super útil para depurar se algo
não estiver colorindo do jeito esperado.

