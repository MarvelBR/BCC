//Exemplo de violação do Princípio da Responsabilidade Única (SRP)
class Player {

  void calculaDano() {
    dano = "calcula o dano";
    System.out.println(dano);
  }

}

//Exemplo usando o Princípio da Responsabilidade Única (SRP)
class Console {
    void imprimeDano(Player player){ 
        double dano = player.calculaDano();
        System.out.println(dano);
    }
}

class Player {

  void calculaDano() {
    double dano = "calcula o dano"; //lógica de cálculo de dano
    return dano;
  }

}
