# Princípios SOLID

Os Princípios escolhidos foram:
1. Princípio da Responsabilidade Única (SRP)
2. Princípio Aberto/Fechado (OCP)
3. Prefira Composição a Herança
4. Princípio de Demeter

O tema geral dos exemplos será em contextos de jogos.
---

## ✅ SRP — Single Responsibility Principle

**O que é?**  
O princípio diz que toda classe deve ter uma única responsabilidade, ou seja, deve existir uma razão única para ela mudar.

**Exemplo Errado:**
```java 
//Exemplo de violação do Princípio da Responsabilidade Única (SRP)
class Player {

  void calculaDano() {
    dano = "calcula o dano";
    System.out.println(dano);
  }

}
```
Nesse exemplo a classe Player tanto calcula a lógica do dano quando imprime ele!

**Problema Resolvido:**  
🔗 [SRP/player.java](./SRP/player.java)

Evita que a classe Player fique com múltiplas responsabilidades.

---

## ✅ OCP — Open-Closed Principle

**O que é?**  
Esse princípio diz que as classes devem estar abertas para extensões, mas fechadas para modificações.

**Exemplo Errado:**
```java 
// Exemplo de violação do OCP
class Arma {

    void atacar(String tipo) {
        if (tipo.equals("Espada")) {
            System.out.println("ataque cortante");
        } else if (tipo.equals("Arco")) {
            System.out.println("ataque à distância");
        }
    }
}
```
Nesse exemplo se você quiser adicionar um novo tipo de arma (ex.: "Machado", "Lança"), precisará modificar o método atacar() para adicionar outro if/else. Isso viola o OCP, pois a classe não está fechada para modificação!

**Problema Resolvido:**  

🔗 [OCP/arma.java](./OCP/arma.java)

Agora novas armas podem ser adicionadas criando novas classes, ou seja, sem modificar a classe Arma, então a classe Arma está fechada para modificações, mas aberta para extensões.

---

## ✅ Prefira Composição a Herança

**O que é?**  
Sempre que possível, prefira criar classes com composição (usar outras classes como membros) ao invés de usar herança.

**Exemplo Errado:**
```java 
// Exemplo de violação da composição
class Inventario {
    void usarItem() {
        System.out.println("usa item do inventário");
    }
}

class Player extends Inventario {
    void agir() {
        usarItem();  // herdado
    }
}
```

**Problema Resolvido:**  

🔗 [Prefira Composição a Herança/inventario.java](./Prefira%20Composição%20a%20Herança/inventario.java)

Agora a classe Player não herda a Inventory e sim, diz que o Player "tem um" Inventario.

---

## ✅ Princípio de Demeter

**O que é?**  
O princípio diz que uma classe deve conhecer o mínimo possível sobre as estruturas internas de outras classes.

**Exemplo Errado:**
```java 
// Exemplo violando o Princípio de Demeter
class Item {
    void usar() {
        System.out.println("Item usado!");
    }
}

class Inventario {
    Item itemEquipado = new Item();

    Item getItemEquipado() {
        return itemEquipado;
    }
}

class Player {
    Inventario inventario = new Inventario();

    void usarItemEquipado() {
        //Acessando internamente demais: inventario -> item -> usar
        inventario.getItemEquipado().usar();
    }
}
```

O método usarItemEquipado() da classe Player acessa Item através de uma sequência de chamadas (inventario.getItemEquipado().usar()). Isso viola o Princípio de Demeter!

**Problema Resolvido:**  

🔗 [Demeter/item.java](./Demeter/item.java)

Player não precisa mais navegar por múltiplos objetos para chamar usar()

---

## Referências Bibliográficas

Engenharia de Software Moderda (Capítulo 5): (https://engsoftmoderna.info/cap5.html)
