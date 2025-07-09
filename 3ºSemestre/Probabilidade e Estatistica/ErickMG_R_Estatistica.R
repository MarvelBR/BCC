## **EXERCÍCIOS PRÁTICOS PARA CASA**

### Exercício 1: Controle de Qualidade
#Uma fábrica produz parafusos com diâmetro médio de 5mm. Colete uma amostra de 30 parafusos e teste se o processo está sob controle.

set.seed(123)
# Gerando uma amostra de 30 parafusos com média 5.0 e desvio padrão 0.1
amostra <- rnorm(30, mean = 5.0, sd = 0.1)

# Realizando o teste t para verificar se a média é igual a 5.0
teste <- t.test(amostra, mu = 5.0)

# Mostrar resultados
print(teste)

### Exercício 2: Pesquisa de Satisfação
#Compare a satisfação de clientes entre duas filiais usando teste t e calcule o poder do teste.

set.seed(456)

# Simulando notas de satisfação (1 a 10) para duas filiais
filial_A <- rnorm(30, mean = 7.5, sd = 1.2)
filial_B <- rnorm(30, mean = 6.9, sd = 1.3)

# Teste t de duas amostras
teste_t <- t.test(filial_A, filial_B, var.equal = TRUE)

print(teste_t)

# Calcular médias e desvios padrão
media_A <- mean(filial_A)
media_B <- mean(filial_B)
desvio_A <- sd(filial_A)
desvio_B <- sd(filial_B)

# Calcular desvio combinado
desvio_combinado <- sqrt((desvio_A^2 + desvio_B^2) / 2)

# Calcular tamanho do efeito 
d_real <- abs(media_A - media_B) / desvio_combinado

# Calcular poder do teste
library(pwr)
poder <- pwr.t.test(n = 30, d = d_real, sig.level = 0.05, type = "two.sample", alternative = "two.sided")

print(poder)

### Exercício 3: Análise de Poisson
#Analise o número de chamadas em um call center por hora e ajuste uma distribuição de Poisson.
set.seed(789)

# Simulando o número de chamadas recebidas por hora (ex: 50 horas)
chamadas_por_hora <- rpois(50, lambda = 6) # Média de 6 chamadas por hora

# Ajuste visual da distribuição
hist(chamadas, probability = TRUE, col = "lightblue", main = "Chamadas por hora")
lines(0:max(chamadas), dpois(0:max(chamadas), lambda = mean(chamadas)), type = "h", col = "red", lwd = 2)

# Teste de aderência qui-quadrado
observado <- table(factor(chamadas, levels = 0:max(chamadas)))
esperado <- dpois(0:max(chamadas), lambda = mean(chamadas)) * length(chamadas)
chisq.test(x = observado, p = esperado / sum(esperado))

