# Objetivo do Projeto

Implementar um sistema de envio de notificações que permita a fácil adição de novos canais de envio (ex: Email, SMS, Push) e diferentes tipos de mensagens. Este projeto visa aplicar os padrões de projeto Strategy para os mecanismos de envio e Simple Factory para a criação de mensagens. Ao final, o aluno deverá ser capaz de entender como esses padrões promovem a flexibilidade e a manutenibilidade do código. O sistema deve ser modular e capaz de enviar notificações. O sistema deve ter diferentes estratégias de enviar uma notificação (Email, SMS). Cada forma será uma estratégia separada, permitindo que o cliente escolha ou altere o método de envio dinamicamente. Também, deve haver uma maneira centralizada e simplificada para criar diferentes tipos de objetos de mensagem (ex: Mensagem Simples, Mensagem Urgente) sem expor a lógica de criação ao cliente. 
Por fim, deve haver um serviço de notificação para enviar uma mensagem criada.

---

# Tarefas Específicas

Você deve:

1. **Analisar o Esqueleto Fornecido**: Entender a estrutura inicial e os papéis de cada interface/classe.  
   - Anotar em cada classe o que é contexto, cliente, estratégia concreta, etc

2. **Definir/Completar Interfaces e Classes Necessárias para Execução** : F**a;lta código em vários pontos.**

3. **Adicionar um novo tipo de mensagem**, como `PromotionalMessage`.

4. **Testar**: Garantir que o sistema funciona como esperado, incluindo a troca de estratégias e a criação de diferentes tipos de mensagem.

5. **Substituir o Simple Factory pelo Factory Method** testar novamente usando um novo padrão.