{Aluno: Erick Molina Gehring}
{RA: 2251680}

inteiro: dividendo
inteiro: divisor

inteiro resto(inteiro: dividendo, inteiro: divisor)
    inteiro: resto
    se divisor = 0 então {não permite divisão por 0}
        retorna(-1)
    fim

    resto := dividendo

    repita
        resto := resto - divisor
    até resto < divisor

    retorna(r)
fim

inteiro principal()
    leia(dividendo)
    leia(divisor)
    escreva(resto(dividendo, divisor))
    retorna(0)
fim