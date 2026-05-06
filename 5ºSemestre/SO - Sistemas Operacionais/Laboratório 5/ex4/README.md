# EX4 - Serviço de Tradução com Socket UNIX + Fork
## Questão 5(a) - Laboratório 5: IPC

---

## DESCRIÇÃO
Dois programas implementam um serviço de tradução de palavras:
- **server**: servidor UNIX socket que cria um processo filho (`fork`) para cada cliente conectado.
- **client**: cliente que envia requisições de tradução e recebe as respostas.

### Protocolo:
- **Requisição**: `LANG:PALAVRA\n` (ex: `"pt-en:cachorro\n"`)
- **Resposta**: `TRADUÇÃO\n` (ex: `"dog\n"`) ou `ERROR:UNKNOWN\n`
- **Encerrar**: `NO-NO\n`

### Idiomas suportados (ISO 639-1):
`pt-en`, `en-pt`, `pt-es`, `es-pt`, `en-es`, `es-en`

## COMO COMPILAR
```bash
make
```

## COMO EXECUTAR
1. **Terminal 1 (servidor):**
   ```bash
   ./server
   ```

2. **Terminal 2+ (clientes – múltiplos simultâneos suportados):**
   ```bash
   ./client
   ```

## BIBLIOTECAS USADAS
### Padrão C
- `stdio.h`: Entrada e saída (printf, snprintf, perror).
- `stdlib.h`: Controle de processos (exit).
- `string.h`: Manipulação de strings e buffers (strcmp, strncpy, strchr).
- `ctype.h`: Normalização de texto para minúsculas (`tolower`).

### POSIX (Sistema Operacional)
- `sys/socket.h`: API principal de sockets (`socket`, `bind`, `listen`, `accept`, `connect`).
- `sys/un.h`: Estruturas para endereçamento de Sockets de Domínio UNIX (AF_UNIX).
- `sys/wait.h`: Gerenciamento de processos filhos e limpeza de zumbis (`waitpid`).
- `signal.h`: Tratamento de sinais (`sigaction`, `SIGCHLD`) para automação da limpeza de processos.
- `unistd.h`: Chamadas de sistema fundamentais (`fork`, `read`, `write`, `close`, `unlink`).
- `errno.h`: Tratamento de interrupções de sistema (EINTR).

## SOCKET UNIX
- `/tmp/traducao_socket` (removido automaticamente ao iniciar o servidor)

## PALAVRAS SUPORTADAS (Dicionário)
- **pt-en**: cachorro → dog, gato → cat, casa → house, carro → car, computador → computer, livro → book, agua → water, pão → bread, escola → school, amigo → friend, sol → sun, lua → moon, cidade → city, tempo → weather, trabalho → work.
- **en-pt**: (inverso do pt-en)
- **pt-es**: cachorro → perro, gato → gato, casa → casa, carro → coche, amigo → amigo.
- **es-pt**: (inverso do pt-es)
- **en-es**: dog → perro, cat → gato, house → casa, car → coche, friend → amigo.
- **es-en**: (inverso do en-es)

## EXEMPLO DE USO
**Servidor:**
```text
$ ./server
[servidor] Serviço de tradução iniciado.
[servidor] Socket: /tmp/traducao_socket
[servidor] Aguardando conexões...
```

**Cliente:**
```text
$ ./client
[cliente] Conectado ao servidor.

traduzir> pt-en:cachorro
[resultado] dog

traduzir> en-pt:house
[resultado] casa

traduzir> NO-NO
[cliente] Servidor respondeu: CONEXAO_ENCERRADA
[cliente] Encerrando.
```

## CASOS DE TESTE
- `pt-en:cachorro` → `dog`
- `pt-en:gato` → `cat`
- `en-pt:water` → `agua`
- `pt-es:carro` → `coche`
- `es-en:perro` → `dog`
- `pt-en:xyz` → `ERROR:UNKNOWN`
- `INVALIDO` → `ERROR:FORMATO_INVALIDO`
