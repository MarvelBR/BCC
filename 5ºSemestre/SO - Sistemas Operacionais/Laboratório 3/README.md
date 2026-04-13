# BCC34G - Sistemas Operacionais

## Laboratório 3: Manipulação de Threads - Parte 2

**Autor:** Erick Molina Gehring  
**Data:** 13/04/2026

---

## Como Compilar

Na pasta do projeto, execute:

```bash
make
```

Para remover os binários compilados:

```bash
make clean
```

**Requisitos:** GCC com suporte a `pthreads` e biblioteca matemática (`-lm`).

## Bibliotecas Utilizadas

*   `pthread.h`: Manipulação de threads POSIX, mutexes e sincronização.
*   `math.h`: Funções matemáticas para cálculo de logaritmo e exponencial (usado na média geométrica).
*   `time.h`: Geração de sementes aleatórias para o vetor e matriz.
*   `matriz.h`: Biblioteca auxiliar para manipulação de matrizes dinâmicas.

---

## Questão 1 - busca_vetor_threads

### Descrição
Localiza um valor alvo em um vetor de inteiros dividindo o espaço de busca entre $N$ threads. Utiliza um mutex para garantir que apenas uma thread atualize o índice global de "encontrado".

### Como Executar
```bash
./busca_vetor_threads <tamanho_vetor> <num_threads> <valor_alvo>
```

### Exemplo de Uso
```bash
$ ./busca_vetor_threads 10000 4 500
Thread 0 encontrou o valor 500 na posicao 834
Resultado: Valor 500 encontrado no indice 834
```

---

## Questão 2 - matriz_threads

### Descrição
Calcula simultaneamente a média aritmética das linhas e a média geométrica das colunas de uma matriz MxN. 
*   **Paralelização de Funções:** Threads divididas entre os dois tipos de cálculo.
*   **Paralelização de Dados:** Cada conjunto de threads divide as linhas/colunas entre si.

### Como Executar
```bash
./matriz_threads <num_threads> <arquivo_entrada> <arquivo_saida> [gerar M N]
```
*   `gerar M N`: (Opcional) Cria uma matriz aleatória de tamanho MxN no arquivo de entrada antes de processar.

### Exemplo de Uso
```bash
# Exemplo 1: Usando arquivo existente
$ ./matriz_threads 4 matriz_6por8.in resultados.txt
Resultados salvos com sucesso em: resultados.txt

No resultados.txt:
Medias Aritmeticas das Linhas (M):
L[0]: 4.5000
L[1]: 5.5000
L[2]: 6.5000
L[3]: 7.5000
L[4]: 8.5000
L[5]: 9.5000

Medias Geometricas das Colunas (N):
C[0]: 2.9938
C[1]: 4.1407
C[2]: 5.2169
C[3]: 6.2652
C[4]: 7.2989
C[5]: 8.3239
C[6]: 9.3433
C[7]: 10.3588
```

```bash
# Exemplo 2: Gerando nova matriz e processando
$ ./matriz_threads 8 dados.in resultados.txt 100 200
Matriz 100x200 gerada e salva em dados.in
Resultados salvos com sucesso em: resultados.txt

No resultados.txt:
Medias Aritmeticas das Linhas (M):
L[0]: 45.9000
L[1]: 60.5000
L[2]: 60.5000
L[3]: 57.0000
L[4]: 40.2000
L[5]: 44.2000
L[6]: 47.4000
L[7]: 46.5000
L[8]: 55.0000
L[9]: 47.9000

Medias Geometricas das Colunas (N):
C[0]: 38.4260
C[1]: 29.5350
C[2]: 42.7616
C[3]: 32.4109
C[4]: 66.7028
C[5]: 28.9242
C[6]: 52.1505
C[7]: 31.7151
C[8]: 40.3509
C[9]: 30.5643
```

---

## Casos de Teste (Questão 3 - Parte 1)

Para os testes de hardware e tempo solicitados na Parte 1, sugere-se o uso do comando `time`:

```bash
time ./matriz_threads 1 dados.in res.txt
time ./matriz_threads 2 dados.in res.txt
time ./matriz_threads 4 dados.in res.txt
time ./matriz_threads 8 dados.in res.txt
time ./matriz_threads 16 dados.in res.txt
```
