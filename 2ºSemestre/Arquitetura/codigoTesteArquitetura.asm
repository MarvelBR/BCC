Main:
    # Inicializa variáveis x, y
    addi $s1, $0, 3                # x = 3
    addi $s2, $0, 2                # y = 2
    # Variável resultado
    add $s0, $0, $0          # resultado = 0

    # Instruções R (Add, Sub, And, Or, Xor)
    add $s0, $s1, $s2        # Add: resultado = x + y
    sub $s0, $s1, $s2        # Sub: resultado = x - y
    and $s0, $s1, $s2        # And: resultado = x & y
    or  $s0, $s1, $s2        # Or: resultado = x | y
    xor $s0, $s1, $s2        # Xor: resultado = x ^ y

    # Instruções com Imediato (Addi, Andi, Ori)
    addi $s0, $s1, 5         # Addi: resultado = x + 5
    andi $s0, $s1, 5         # Andi: resultado = x & 5
    ori $s0, $s1, 5         # Ori: resultado = x | 5

    # Desvios Condicionais (Beq, Bne)
    #if (x == y) {
        #resultado += y;
    #} else { 
        #resultado += x;
    #}
    bne $s1, $s2, Else1 # se x != y, vai para o Else
    add $s0, $s0, $s2  # se x == y, continua aqui ->  resultado += y
    j MaiorQue 
    
Else1: add $s0, $s0, $s1  #resultado do Else -> resultado += x
       
MaiorQue:
    #if (x > y) {  // Slt
        #resultado = x+y;
    #}
    slt $t1, $s1, $s2
    beq $t1, $0, Memoria
    add $s0, $s1, $s2 #resultado = x+y

Memoria:
    #int memoria[10]; //$s3
    #memoria[0] = 42;  // Sw
    #resultado = memoria[0];  // Lw
    addi $sp, $sp, -4  # Reserva espaço na pilha
    addi $t2, $0, 42   # Define o valor 42
    sw $t2, 0($sp)     # Armazena 42 na pilha
    lw $s0, 0($sp)     # Carrega o valor salvo para $s0
    addi $sp, $sp, 4   # Libera o espaço da pilha
    
    add $t3, $0, $0 # i do For
    
For:
    #for (int i = 0; i < x; i++) {
        #resultado+=i;
    #}
    slt $t4, $t3, $s1
    beq $t4, $0, Inicia_While
    add $s0, $s0, $t3
    addi $t3, $t3, 1
    j For

Inicia_While:
    add $t3, $0, $0 # i do While

While:
    #int i = 0;
    #while (i < y) {
        #resultado+=i;
        #i++;
    #}
    slt $t4, $t3, $s2  
    beq $t4, $0, Inicia_For_Aninhado
    add $s0, $s0, $t3
    addi $t3, $t3, 1
    j While
    
Inicia_For_Aninhado:
    add $t3, $0, $0 # i do While
    
For_Aninhado:
    #for (int i = 0; i < x; i++) {
        #for (int j = 0; j < y; j++) {
            #resultado+=i+j;
        #}
    #}
    slt $t4, $t3, $s1  
    beq $t4, $0, Chamada_Funcao
    add $t5, $0, $0 # j do For Aninhado
    
For_Aninhado2:
    slt $t6, $t5, $s2
    beq $t6, $0, Fim_For_Aninhado
    add $t7, $t3, $t5
    add $s0, $s0, $t7
    addi $t5, $t5, 1
    j Fim_For_Aninhado
    
Fim_For_Aninhado:
    addi $t3, $t3, 1
    j For_Aninhado
    
Chamada_Funcao:
    # Chamada de Função Folha
    #resultado = soma(x, y);
    add $a0, $0, $s1
    add $a1, $0, $s2
    jal Soma
    add $s0, $0, $v0
    
    # Chamada de Função Não-Folha
    #resultado = multiplicarPor2(x, y);
    jal MultiplicarPor2
    add $s0, $0, $v0
    j Fim
    
# Função Soma (Chamada de função folha)
Soma:
    add $v0, $a0, $a1       # soma a0 e a1, e armazena em v0 (retorno)
    jr $ra                   # retorna para a chamada anterior

# Função MultiplicarPor2 (Chama soma)
MultiplicarPor2:
    # Chama Soma
    addi $sp, $sp, -4   #Salvando na pilha
    sw $ra, 0($sp)
    jal Soma
    lw $ra, 0($sp)
    # multiplica o resultado por 2
    sll $v0, $v0, 1          # desloca v0 para a esquerda (multiplica por 2)
    addi $sp, $sp, 4
    jr $ra                   # retorna para a chamada anterior

Fim:
    j Fim