# Exercício 2 - Barbeiro Dorminhoco

Solução do problema do barbeiro dorminhoco usando monitor implementado com mutex e variáveis de condição POSIX.

## Compilar

```bash
make
```

## Executar

```bash
make run
```

O programa cria um barbeiro e vários clientes. O barbeiro dorme quando não há clientes, acorda quando um cliente chega, atende um cliente por vez, mantém uma sala de espera com capacidade limitada e faz clientes irem embora quando todas as cadeiras estão ocupadas.
