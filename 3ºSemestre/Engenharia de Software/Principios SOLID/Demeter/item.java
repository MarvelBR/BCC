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

// Exemplo usando o Princípio de Demeter
class Item {
    void usar() {
        System.out.println("Item usado!");
    }
}
class Inventario {
    Item itemEquipado = new Item();

    void usarItemEquipado() {
        itemEquipado.usar();
    }
}
class Player {
    Inventario inventario = new Inventario();

    void usarItemEquipado() {
        // Acessando diretamente o item
        inventario.usarItemEquipado();
    }
}
