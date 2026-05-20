# Exercício 1 - Jantar dos Filósofos

Solução do problema do jantar dos filósofos usando semáforos POSIX.

## Compilar

```bash
make
```

## Executar

```bash
make run
```

O programa cria cinco filósofos. Cada filósofo alterna entre pensar, tentar pegar os garfos, comer e largar os garfos. A solução usa exclusão mútua e um semáforo individual por filósofo para evitar deadlock.
