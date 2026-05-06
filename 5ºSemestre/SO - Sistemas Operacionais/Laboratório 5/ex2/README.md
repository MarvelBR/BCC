# EX2 - Manipulação de Arquivo com Graceful Stop
## Questão 2(b) - Laboratório 5: IPC

---

## DESCRIÇÃO
Programa que lê linhas do usuário e as armazena em um buffer interno em memória. A cada `BUFFER_MAX` (16) linhas, o buffer é automaticamente gravado no arquivo `dados.txt`.

Ao receber `SIGINT` (Ctrl+C) ou `SIGTERM` (kill -15 <PID>), o programa realiza uma **finalização limpa (graceful stop)**:
1. Grava no arquivo todas as linhas ainda pendentes em memória.
2. Fecha o arquivo de forma segura.
3. Encerra o processo.

## COMO COMPILAR
```bash
make
```

## COMO EXECUTAR
```bash
./file_handler
```

## ENVIANDO SINAIS MANUALMENTE
Em outro terminal, obtenha o PID exibido pelo programa e execute:
```bash
kill -2  <PID>     # SIGINT  (equivalente a Ctrl+C)
kill -15 <PID>     # SIGTERM
```

## BIBLIOTECAS USADAS
### Padrão C
- `stdio.h`: Operações de arquivo em alto nível (fopen, fprintf, fflush, fclose).
- `stdlib.h`: Controle de execução do processo (exit).
- `string.h`: Manipulação de buffers e nomes de sinais (strncpy, memset, strlen).
- `time.h`: Manipulação de data e hora para os logs (time, localtime, strftime).

### POSIX (Sistema Operacional)
- `signal.h`: Gerenciamento de sinais e registro de tratadores (`sigaction`, `sig_atomic_t`).
- `unistd.h`: Obtenção do PID (`getpid`) e escrita segura em handlers (`write`).
- `fcntl.h`: Modos de acesso a arquivos e controle.
- `errno.h`: Diagnóstico de erros do sistema.

## ARQUIVO GERADO
- `dados.txt` (no diretório atual)

## EXEMPLO DE USO
```text
$ ./file_handler
[info] Arquivo 'dados.txt' aberto para escrita.
[info] Handlers registrados para SIGINT e SIGTERM.
[info] PID deste processo: 12345

entrada> Hello World
[info] Linha armazenada no buffer (1/16 pendentes).
entrada> Dados importantes
[info] Linha armazenada no buffer (2/16 pendentes).
entrada> ^C
[sinal] Recebido SIGINT - iniciando finalização limpa...
[info] Gravando 2 linha(s) pendente(s) no arquivo...
[info] Gravação concluída.
[info] Arquivo 'dados.txt' fechado com sucesso.
[info] Programa encerrado de forma limpa.

$ cat dados.txt
[2026-05-05 10:30:01] Hello World
[2026-05-05 10:30:05] Dados importantes
```
