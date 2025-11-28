# Construção de Um Mecanismo de Indexação de Arquivos

## Como Executar?

### 1. Compilação
1. Na raiz do projeto, compile com: `make`
2. O executável será criado em:
``` 
build/indice (Linux)
build/indice.exe (Windows)
```
3. Obs: Como estou utilizando o windows, seguirei o resto do "tutorial" de como rodar com `indice.exe`

### 2. Construir o índice
1. Constrói o índice invertido a partir dos arquivos **.txt** dentro de um diretório.
    1. Exemplo: `./build/indice.exe construir data/machado`

2. Saída esperada: 
```
Indexacao completa. Documentos processados: 20
Indexacao concluida. index.dat salvo.
```

3. Isso cria (ou sobrescreve) o arquivo: `index.dat`
    1. Que contém o índice binário serializado.

### 3. Buscar termos
1. Exemplo de busca simples:
    1. `./build/indice.exe buscar amor`

2. Exemplo de busca com vários termos:
    1. `./build/indice.exe buscar bentinho capitu`

    2. Saída:
        1. `data/machado/romance/domCasmurro.txt`
        * Ou seja: apenas documentos que possuem todos os termos aparecem no resultado.
