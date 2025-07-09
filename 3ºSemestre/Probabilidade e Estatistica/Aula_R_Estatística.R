# Aula: R na Estatística - Aplicações Práticas

## **PARTE 1: Introdução ao R e Conceitos Básicos (20 min)**

### Por que usar R na Estatística?
#**Gratuito e open-source**
#**Visualizações poderosas**
#**Funções estatísticas prontas**
#**Reprodutibilidade**
#**Comunidade ativa**

### Primeiros Passos no R

# Instalação básica já feita
# Vamos começar com operações simples

# Operações básicas
2 + 3
sqrt(16)
log(10)

# Criando vetores
dados <- c(1, 2, 3, 4, 5)
print(dados)
mean(dados)
sd(dados)


### Conceitos Fundamentais

# Estatísticas descritivas
x <- c(12, 15, 18, 20, 22, 25, 28, 30, 32, 35)
summary(x)
var(x)      # Variância
sd(x)       # Desvio padrão
length(x)   # Tamanho da amostra

## **PARTE 2: Probabilidade e Distribuições (30 min)**

### Probabilidade Básica

# Simulando lançamento de moeda
set.seed(123)  # Para reprodutibilidade
moedas <- sample(c("Cara", "Coroa"), 1000, replace = TRUE)
table(moedas)
prop.table(table(moedas))

### Distribuições Discretas

#### Distribuição Binomial

# Exemplo: 10 lançamentos de moeda, P(sucesso) = 0.5
# Probabilidade de exatamente 6 sucessos
dbinom(6, 10, 0.5)

# Probabilidade de até 6 sucessos
pbinom(6, 10, 0.5)

# Gerando valores aleatórios
rbinom(20, 10, 0.5)

# Visualização
x <- 0:10
prob <- dbinom(x, 10, 0.5)
barplot(prob, names.arg = x, 
        main = "Distribuição Binomial (n=10, p=0.5)",
        xlab = "Número de sucessos", ylab = "Probabilidade")

#### Distribuição de Poisson

# Exemplo: λ = 3 (média de eventos por unidade de tempo)
# Probabilidade de exatamente 5 eventos
dpois(5, 3)

# Probabilidade de até 5 eventos
ppois(5, 3)

# Visualização
x <- 0:10
prob <- dpois(x, 3)
barplot(prob, names.arg = x,
        main = "Distribuição de Poisson (λ=3)",
        xlab = "Número de eventos", ylab = "Probabilidade")


### Distribuições Contínuas

#### Distribuição Normal

# Distribuição Normal Padrão (μ=0, σ=1)
# Probabilidade de Z ≤ 1.96
pnorm(1.96)

# Valor crítico para 95% de confiança
qnorm(0.975)

# Gerando valores aleatórios
valores_normais <- rnorm(1000, mean = 100, sd = 15)
hist(valores_normais, main = "Distribuição Normal (μ=100, σ=15)",
     xlab = "Valores", ylab = "Frequência", col = "lightblue")

# Adicionando curva normal teórica
curve(dnorm(x, 100, 15) * length(valores_normais) * 
      (max(valores_normais) - min(valores_normais)) / 30,
      add = TRUE, col = "red", lwd = 2)

## **PARTE 3: Inferência Estatística e TCL (25 min)**

### Teorema Central do Limite - Demonstração

# Simulando TCL com distribuição uniforme
set.seed(456)
n_amostras <- 1000
tamanho_amostra <- 30

# População uniforme (não normal)
medias_amostrais <- replicate(n_amostras, 
                              mean(runif(tamanho_amostra, 0, 10)))

# Visualizando
par(mfrow = c(1, 2))

# População original (uniforme)
hist(runif(1000, 0, 10), main = "População Original (Uniforme)",
     xlab = "Valores", col = "lightcoral")

# Distribuição das médias amostrais
hist(medias_amostrais, main = "Distribuição das Médias Amostrais",
     xlab = "Médias", col = "lightblue")

# Verificando normalidade
shapiro.test(medias_amostrais[1:5000])  # Limitando para o teste


### Intervalos de Confiança

# Exemplo prático: altura de estudantes
alturas <- rnorm(50, 170, 10)  # Simulando dados

# IC para média (σ conhecido)
media <- mean(alturas)
erro_padrao <- 10/sqrt(50)
ic_95 <- c(media - 1.96*erro_padrao, media + 1.96*erro_padrao)

cat("Intervalo de Confiança 95%:", ic_95[1], "a", ic_95[2], "\n")

# IC usando t (σ desconhecido)
t.test(alturas, conf.level = 0.95)


## **PARTE 4: Testes de Hipóteses (20 min)**

### Teste de Hipótese para Média

#### Teste t para uma amostra

# H0: μ = 170 vs H1: μ ≠ 170
# Usando os dados de altura anteriores

resultado_teste <- t.test(alturas, mu = 170)
print(resultado_teste)

# Interpretação
cat("Valor p:", resultado_teste$p.value, "\n")
cat("Estatística t:", resultado_teste$statistic, "\n")
cat("Graus de liberdade:", resultado_teste$parameter, "\n")


#### Teste t para duas amostras

# Comparando alturas de homens e mulheres
homens <- rnorm(30, 175, 8)
mulheres <- rnorm(30, 165, 7)

# Teste t independente
t.test(homens, mulheres, var.equal = TRUE)

# Visualização
boxplot(homens, mulheres, 
        names = c("Homens", "Mulheres"),
        main = "Comparação de Alturas",
        ylab = "Altura (cm)")

### Interpretação do Valor-p

# Função para interpretar valor-p
interpretar_p <- function(p_valor) {
  if (p_valor < 0.001) {
    return("Evidência muito forte contra H0")
  } else if (p_valor < 0.01) {
    return("Evidência forte contra H0")
  } else if (p_valor < 0.05) {
    return("Evidência contra H0")
  } else {
    return("Evidência insuficiente contra H0")
  }
}

# Exemplo de uso
p <- 0.023
cat("Valor-p:", p, "\n")
cat("Interpretação:", interpretar_p(p), "\n")


## **PARTE 5: Poder do Teste e Análise de Poder (15 min)**

### Calculando o Poder do Teste

# Instalando pacote para análise de poder (se necessário)
# install.packages("pwr")
library(pwr)

# Poder para teste t de uma amostra
# Detectar diferença de 5 unidades com α = 0.05
poder_teste <- pwr.t.test(d = 5/10,           # Tamanho do efeito
                          sig.level = 0.05,   # Nível de significância
                          power = NULL,       # Queremos calcular
                          n = 25)             # Tamanho da amostra

print(poder_teste)

# Tamanho da amostra necessário para poder = 0.8
tamanho_amostra <- pwr.t.test(d = 5/10,
                              sig.level = 0.05,
                              power = 0.8,
                              n = NULL)
print(tamanho_amostra)


### Curva de Poder

# Visualizando como o poder varia com o tamanho da amostra
ns <- seq(5, 50, by = 5)
poderes <- sapply(ns, function(n) 
  pwr.t.test(d = 5/10, sig.level = 0.05, n = n)$power)

plot(ns, poderes, type = "b", 
     main = "Curva de Poder vs Tamanho da Amostra",
     xlab = "Tamanho da Amostra", ylab = "Poder do Teste",
     col = "blue", lwd = 2)
abline(h = 0.8, col = "red", lty = 2)
text(35, 0.82, "Poder = 0.8", col = "red")


## **PARTE 6: Projeto Integrador - Estudo de Caso (10 min)**

### Análise Completa: Eficácia de um Medicamento

# Simulando dados de um estudo clínico
set.seed(789)
grupo_controle <- rnorm(40, 10, 2)      # Placebo
grupo_tratamento <- rnorm(40, 12, 2)    # Medicamento

# 1. Análise Descritiva
summary(grupo_controle)
summary(grupo_tratamento)

# 2. Visualização
boxplot(grupo_controle, grupo_tratamento,
        names = c("Controle", "Tratamento"),
        main = "Eficácia do Medicamento",
        ylab = "Melhora no Sintoma")

# 3. Teste de Normalidade
shapiro.test(grupo_controle)
shapiro.test(grupo_tratamento)

# 4. Teste de Hipótese
resultado_final <- t.test(grupo_tratamento, grupo_controle, 
                          alternative = "greater")
print(resultado_final)

# 5. Tamanho do Efeito
diferenca <- mean(grupo_tratamento) - mean(grupo_controle)
desvio_combinado <- sqrt((var(grupo_controle) + var(grupo_tratamento))/2)
cohen_d <- diferenca / desvio_combinado
cat("Tamanho do efeito (Cohen's d):", cohen_d, "\n")

# 6. Intervalo de Confiança para a diferença
cat("IC 95% para diferença:", resultado_final$conf.int, "\n")


## **EXERCÍCIOS PRÁTICOS PARA CASA**

### Exercício 1: Controle de Qualidade
Uma fábrica produz parafusos com diâmetro médio de 5mm. Colete uma amostra de 30 parafusos e teste se o processo está sob controle.

### Exercício 2: Pesquisa de Satisfação
Compare a satisfação de clientes entre duas filiais usando teste t e calcule o poder do teste.

### Exercício 3: Análise de Poisson
Analise o número de chamadas em um call center por hora e ajuste uma distribuição de Poisson.


## **RECURSOS ADICIONAIS**

### Comandos Essenciais para Lembrar

# Distribuições
dnorm(), pnorm(), qnorm(), rnorm()    # Normal
dbinom(), pbinom(), rbinom()          # Binomial
dpois(), ppois(), rpois()             # Poisson

# Testes
t.test()                              # Teste t
shapiro.test()                        # Normalidade
var.test()                            # Homogeneidade de variâncias

# Gráficos
hist()                                # Histograma
boxplot()                             # Box plot
plot()                                # Gráfico de dispersão

# Análise de Poder
library(pwr)
pwr.t.test()                          # Poder para teste t


### Próximos Passos
1. **Regressão Linear**: `lm()` e `summary()`
2. **ANOVA**: `aov()` e `TukeyHSD()`
3. **Testes Não-paramétricos**: `wilcox.test()`, `kruskal.test()`
4. **Visualização Avançada**: `ggplot2`
5. **Análise Multivariada**: `princomp()`, `cluster`


## **DICAS FINAIS**

**Sempre use `set.seed()`** para análises reprodutíveis
**Visualize seus dados** antes de qualquer teste
**Verifique pressupostos** (normalidade, homocedasticidade)
**Interprete resultados** no contexto do problema
**Documente seu código** com comentários claros

**Lembre-se:** R é uma ferramenta poderosa, mas a interpretação estatística correta é fundamental!