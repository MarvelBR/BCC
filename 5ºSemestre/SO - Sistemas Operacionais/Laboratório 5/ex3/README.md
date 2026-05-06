# EX3 - Soma de Vetores com Memória Compartilhada e Pipes
## Questão 4 - Laboratório 5: IPC

---

## DESCRIÇÃO
Programa que realiza a soma `V3 = V1 + V2` de forma paralela, usando múltiplos processos filhos. Os vetores V1, V2 e V3 ficam em memória compartilhada (System V IPC - `shmget`/`shmat`). O pai distribui intervalos de índices para cada filho via pipes.

### Fluxo:
1. Pai solicita ao usuário: `n_elem` e `n_proc`.
2. Pai cria memória compartilhada para V1, V2, V3.
3. Pai preenche V1 e V2 com valores aleatórios (0-99).
4. Pai cria um pipe para cada filho.
5. Pai faz `fork` dos filhos.
6. Cada filho bloqueia lendo seu pipe (aguarda o intervalo).
7. Pai calcula e envia o intervalo para cada filho.
8. Cada filho soma `V1[i] + V2[i] → V3[i]` no seu intervalo.
9. Pai espera todos os filhos (`waitpid`) e exibe o resultado.

## COMO COMPILAR
```bash
make
```

## COMO EXECUTAR
```bash
./vetor_soma
```

Será solicitado:
- Número de elementos dos vetores.
- Número de processos filhos.

## BIBLIOTECAS USADAS
### Padrão C
- `stdio.h`: Entrada/Saída formatada (scanf, printf, perror).
- `stdlib.h`: Gestão de memória dinâmica (malloc, free) e números aleatórios (rand, srand).
- `string.h`: Limpeza de memória (memset) e utilitários.
- `time.h`: Semente para geração de números aleatórios (`time`).

### POSIX / System V IPC
- `unistd.h`: Criação de processos (`fork`) e comunicação via `pipe`, além de `read`/`write`.
- `sys/ipc.h`: Cabeçalho base para os mecanismos de comunicação System V.
- `sys/shm.h`: Gerenciamento de Memória Compartilhada (`shmget`, `shmat`, `shmdt`, `shmctl`).
- `sys/wait.h`: Sincronização e monitoramento do estado dos filhos (`waitpid`, `WIFEXITED`).

## EXEMPLO DE USO
```text
$ ./vetor_soma
Número de elementos dos vetores: 10
Número de processos filhos    : 3

[pai] Configuração: 10 elemento(s), 3 processo(s) filho(s)
[pai] Memória compartilhada criada (shmid=0, 120 bytes).
[pai] 3 pipe(s) criado(s).
[pai] Distribuindo trabalho...
[pai] Filho 0: índices [0, 4) (4 elemento(s))
[pai] Filho 1: índices [4, 7) (3 elemento(s))
[pai] Filho 2: índices [7, 10) (3 elemento(s))
[pai] Aguardando filhos...
[filho 1] Processando índices [4, 7)...
[filho 0] Processando índices [0, 4)...
[filho 2] Processando índices [7, 10)...
[filho 1] Concluído.
[filho 0] Concluído.
[filho 2] Concluído.
[pai] Filho PID=9005 concluído com sucesso.
[pai] Filho PID=9006 concluído com sucesso.
[pai] Filho PID=9007 concluído com sucesso.

===== Resultado =====
V1 = [20, 13, 4, 63, 23, 72, 32, 71, 51, 93]
V2 = [72, 61, 53, 26, 9, 87, 38, 58, 42, 24]
V3 = [92, 74, 57, 89, 32, 159, 70, 129, 93, 117]

[pai] Verificação OK: V3 = V1 + V2 (todos os 10 elementos).
[pai] Encerrado.
```

## CASOS DE TESTE
- `n_elem=1000`, `n_proc=5` → cada filho processa 200 índices.
- `n_elem=1000`, `n_proc=4` → cada filho processa 250 índices.
- `n_elem=10`, `n_proc=3` → filhos processam 4, 3 e 3 elementos.
- `n_elem=7`, `n_proc=3` → filhos processam 3, 2 e 2 elementos.
