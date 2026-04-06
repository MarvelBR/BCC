# BCC5002 - Sistemas Operacionais

## Laboratório 2: Manipulação de processos - Parte 2

**Autor:** Erick Molina Gehring  
**Data:** 03/04/2026

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

Para compilar apenas um programa específico:

```bash
make hierarquia
make executa_comando
make busca_vetor
make shell
```

**Requisitos:** g++ com suporte a C++17 (padrão em distribuições Linux modernas).

## Bibliotecas Utilizadas

Todas as bibliotecas utilizadas são padrão POSIX, não sendo necessária nenhuma instalação adicional:

*   `unistd.h`: `fork()`, `execvp()`, `getpid()`, `sleep()`
*   `sys/wait.h`: `wait()`, `waitpid()`
*   `sys/types.h`: `pid_t`
*   `cstdio`: `printf()`, `fprintf()`, `fgets()`
*   `cstdlib`: `exit()`, `atoi()`, `malloc()`, `free()`
*   `cstring`: `strtok()`, `strcmp()`, `strlen()`, `strcspn()`
*   `ctime`: `time()` (usado em `busca_vetor` para `srand`)
*   `libgen.h`: `basename()` (usado em `executa_comando`)

---

## Questão 1 - hierarquia

### Descrição
Cria uma hierarquia de processos em árvore binária com $N$ níveis.
Total de processos: $(2^N - 1)$. Exibe a árvore com `pstree` ao final.

### Como Executar
```bash
./hierarquia [N]
```
*   `N` = número de níveis (opcional, padrão: 3)

### Exemplo de Uso
```bash
$ ./hierarquia 3
Criando hierarquia com N = 3 níveis.
Total de processos criados: 7
PID do processo raiz: 53849

 Hierarquia de processos (pstree -p 53849) 
hierarquia(53849)─┬─hierarquia(53850)─┬─hierarquia(53852)─┬─hierarquia(53856)
                  │                   │                   └─hierarquia(53859)
                  │                   └─hierarquia(53854)─┬─hierarquia(53858)
                  │                                       └─hierarquia(53862)
                  ├─hierarquia(53851)─┬─hierarquia(53853)─┬─hierarquia(53857)
                  │                   │                   └─hierarquia(53861)
                  │                   └─hierarquia(53855)─┬─hierarquia(53860)
                  │                                       └─hierarquia(53863)
                  └─sh(53867)───pstree(53868)

Hierarquia encerrada.
```

---

## Questão 2 - executa_comando

### Descrição
Recebe um comando via terminal e o executa como processo filho.
O pai aguarda o filho terminar e exibe o código de saída ou o sinal que o encerrou.

### Como Executar
```bash
./executa_comando <comando> [argumentos...]
```

### Exemplo de Uso
```bash
$ ./executa_comando ping 8.8.8.8 -c 3
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=120 time=15.5 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=120 time=15.5 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=120 time=15.7 ms

--- 8.8.8.8 ping statistics ---
3 packets transmitted, 3 received, 0% packet loss, time 2003ms
rtt min/avg/max/mdev = 15.479/15.576/15.731/0.110 ms
Processo executa_comando finalizado (código de saída: 0).
```

---

## Questão 3 - busca_vetor

### Descrição
Gera um vetor aleatório (valores de 0 a 19) e divide a busca entre $N$ filhos.
Cada filho exibe o PID e as posições onde encontrou o valor.
Se nenhum filho encontrar, o pai exibe: `Pai: valor X não encontrado no vetor.`

### Como Executar
```bash
./busca_vetor
```
*(Os parâmetros são lidos interativamente via stdin)*

### Exemplo de Uso
```bash
$ ./busca_vetor
Busca paralela em vetor 
Tamanho do vetor: 10
Número de filhos: 3
Valor a ser procurado: 5
Vetor gerado: [ 17 14 9 13 5 12 15 7 13 1 ]

Filho PID 38750: valor 5 encontrado na posição 4
```

```bash
Busca paralela em vetor 
Tamanho do vetor: 10
Número de filhos: 3
Valor a ser procurado: 20
Vetor gerado: [ 7 4 16 7 7 10 15 12 18 15 ]

Pai: valor 20 não encontrado no vetor.
```

---

## Questão 4 - shell

### Descrição
Shell simples com prompt interativo. Suporta execução em foreground e background (`&`). Evita processos zumbis recolhendo filhos automaticamente a cada novo prompt.

### Como Executar
```bash
./shell
```

### Exemplo de Uso
```bash
$ ./shell
shell — digite 'exit' para sair 

shell$ ls
busca_vetor  executa_comando  hierarquia  shell  ...

shell$ ping 8.8.8.8 -c 2 &
[Background] PID 1610 iniciado: ping

shell$ ls -l
(executa ls enquanto o ping roda em background)

[Background] Processo 1610 finalizado (código de saída: 0)

shell$ exit
Encerrando shell...
