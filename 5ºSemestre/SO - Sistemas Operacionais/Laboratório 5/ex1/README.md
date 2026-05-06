# EX1 - Análise de Strings via FIFO
## Questão 1(a) - Laboratório 5: IPC

---

## DESCRIÇÃO
Dois programas se comunicam via FIFO nomeado:
- **writer**: lê strings do usuário e envia pelo FIFO.
- **reader**: recebe as strings e exibe tamanho, vogais, consoantes e espaços de cada uma.

## COMO COMPILAR
Execute o comando abaixo no terminal:
```bash
make
```

## COMO EXECUTAR
Abra dois terminais e execute na seguinte ordem:

1. **Terminal 1 (reader, deve ser iniciado primeiro):**
   ```bash
   ./reader
   ```

2. **Terminal 2 (writer):**
   ```bash
   ./writer
   ```

O `reader` exibirá a análise de cada string enviada.
Para encerrar, digite `SAIR` no `writer` (ou utilize `Ctrl+D`).

## BIBLIOTECAS USADAS
### Padrão C
- `stdio.h`: Entrada e saída padrão (printf, fgets, perror).
- `stdlib.h`: Funções utilitárias (exit, malloc).
- `string.h`: Manipulação de strings (strlen, strcmp, strcspn).
- `ctype.h`: Classificação de caracteres (tolower, isalpha).

### POSIX (Sistema Operacional)
- `sys/stat.h`: Definições de estados de arquivos e criação do FIFO (`mkfifo`).
- `sys/types.h`: Definições de tipos de dados de sistema (ssize_t, pid_t).
- `fcntl.h`: Controle de arquivos e modos de abertura (`open`, O_RDONLY, O_WRONLY).
- `unistd.h`: Chamadas de sistema fundamentais (`read`, `write`, `close`, `unlink`).

## FIFO CRIADO
- `/tmp/fifo_ex1_strings` (removido automaticamente ao fim da execução do reader)

## EXEMPLO DE USO
**Terminal 1 (reader):**
```text
$ ./reader
[reader] Abrindo FIFO para leitura...
[reader] Conectado ao writer! Aguardando strings...
```

**Terminal 2 (writer):**
```text
$ ./writer
[writer] Aguardando reader abrir o FIFO...
[writer] Conectado ao reader!
> Ola mundo
> SAIR
```

**Saída do reader:**
```text
┌──────────────────────────────────────┐
│ String     : Ola mundo               │
│ Tamanho    : 9                       │
│ Vogais     : 4                       │
│ Consoantes : 4                       │
│ Espaços    : 1                       │
└──────────────────────────────────────┘
```
