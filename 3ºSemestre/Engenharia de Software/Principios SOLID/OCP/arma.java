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

// Exemplo usando o OCP
class Arma {
    void atacar();
}

class Espada extends Arma {
    void atacar() {
        System.out.println("ataque cortante");
    }
}

class Arco extends Arma {
    void atacar() {
        System.out.println("ataque à distância");
    }
}