
interface NotificationStrategy {

    void send(Message message, String recipient);
}

class EmailNotificationStrategy implements NotificationStrategy {

    @Override
    public void send(Message message, String recipient) {
        System.out.println("Enviando EMAIL para " + recipient + " -- " + message.format());
    }

}

class SMSNotificationStrategy implements NotificationStrategy {

    @Override
    public void send(Message message, String recipient) {
        System.out.println("Enviando SMS para " + recipient + " -- " + message.format());
    }
}

/* 
class MessageFactory {

    public static Message createMessage(String type, String content) {
        if ("SIMPLE".equalsIgnoreCase(type)) {
            return new SimpleMessage(content);
        } else if ("URGENT".equalsIgnoreCase(type)) {
            return new UrgentMessage(content);
        } else if ("PROMOTIONAL".equalsIgnoreCase(type)) {
            return new PromotionalMessage(content);
        }
        throw new IllegalArgumentException("Tipo de mensagem desconhecido: " + type);
    }
}
*/

abstract class Message {

    protected String content;

    public Message(String content) {
        this.content = content;
    }

    public abstract String format(); // Método para formatar a mensagem específica

    public String getContent() {
        return content;
    }
}

class SimpleMessage extends Message {

    public SimpleMessage(String content) {
        super(content);
    }

    @Override
    public String format() {
        return "Mensagem simples: " + content;
    }

}

class UrgentMessage extends Message {

    public UrgentMessage(String content) {
        super(content);
    }

    @Override
    public String format() {
        return "URGENTE!!!!! " + content;
    }

}

class PromotionalMessage extends Message {

    public PromotionalMessage(String content) {
        super(content);
    }

    @Override
    public String format() {
        return "Promoção Relâmpago: " + content;
    }

}

abstract class MessageCreator {

    public Message getMessage(String content) {
        return createMessage(content);
    }

    protected abstract Message createMessage(String content);
}


class SimpleMessageCreator extends MessageCreator {

    @Override
    protected Message createMessage(String content) {
        return new SimpleMessage(content);
    }
}

class UrgentMessageCreator extends MessageCreator {

    @Override
    protected Message createMessage(String content) {
        return new UrgentMessage(content);
    }
}

class PromotionalMessageCreator extends MessageCreator {

    @Override
    protected Message createMessage(String content) {
        return new PromotionalMessage(content);
    }
}

class NotificationService {

    private NotificationStrategy strategy;

    public NotificationService() {
    }

    public NotificationService(NotificationStrategy strategy) {
        this.strategy = strategy;
    }

    public void setStrategy(NotificationStrategy strategy) {
        this.strategy = strategy;
    }

    public void sendNotification(Message message, String recipient) {
        if (strategy == null) {
            System.out.println("Erro: Nenhuma estratégia de notificação foi definida.");
            return;
        }
        if (message == null) {
            System.out.println("Erro: Mensagem não pode ser nula.");
            return;
        }
        strategy.send(message, recipient);
    }
}

public class Main {

    public static void main(String[] args) {
        Message welcomeMessage = new SimpleMessageCreator().getMessage("Bem-vindo(a) ao nosso sistema!");
        Message alertMessage = new UrgentMessageCreator().getMessage("Falha crítica detectada no servidor XYZ. Ação imediata requerida.");
        Message promoMessage = new PromotionalMessageCreator().getMessage("Descontos de até 50% em todos os produtos!");

        NotificationService notificationService = new NotificationService();

        System.out.println("--- Usando Estratégia de Email ---");
        notificationService.setStrategy(new EmailNotificationStrategy());
        notificationService.sendNotification(welcomeMessage, "aluno@exemplo.com");
        notificationService.sendNotification(alertMessage, "admin@exemplo.com");
        notificationService.sendNotification(promoMessage, "cliente@exemplo.com");

        System.out.println("\n");

        System.out.println("--- Mudando para Estratégia de SMS ---");
        notificationService.setStrategy(new SMSNotificationStrategy());
        notificationService.sendNotification(welcomeMessage, "+5511912345678");
        notificationService.sendNotification(alertMessage, "+5521987654321");
        notificationService.sendNotification(promoMessage, "+5521987654369");
    }
}
