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

// Exemplo usando o princípio da composição
class Inventario {
    void usarItem() {
        System.out.println("usa item do inventário");
    }
}
class Player {
    Inventario inventario = new Inventario();

    void agir() {
        inventario.usarItem();  // composição
    }
}
