;; 1) Testar se um elemento é membro de uma lista
;; 2) Calcular o tamanho de uma lista
;; 3) Calcular a soma dos elementos de uma lista
;; 4) Calcular o produto dos elementos de uma lista
;; 5) Reversão de lista
;; 6) Testar se duas listas são iguais
;; 7) Concatenação de duas listas
;; 8) Intersecção de duas listas

;; Para rodar: mit-scheme --quiet --load atividade1.scm --eval '(exit)'


;; 1) Membro de lista
(define (membro? x lst)
  (cond ((null? lst) #f)
        ((equal? x (car lst)) #t)
        (else (membro? x (cdr lst)))))

;; 2) Tamanho
(define (tamanho lst)
  (if (null? lst)
      0
      (+ 1 (tamanho (cdr lst)))))

;; 3) Soma
(define (soma lst)
  (if (null? lst)
      0
      (+ (car lst) (soma (cdr lst)))))

;; 4) Produto
(define (produto lst)
  (if (null? lst)
      1
      (* (car lst) (produto (cdr lst)))))

;; 5) Reversão (com acumulador, O(n))
(define (reverso lst)
  (define (aux lst acc)
    (if (null? lst)
        acc
        (aux (cdr lst) (cons (car lst) acc))))
  (aux lst '()))

;; 6) Igualdade de listas
(define (iguais? l1 l2)
  (cond ((and (null? l1) (null? l2)) #t)
        ((or (null? l1) (null? l2)) #f)
        ((equal? (car l1) (car l2)) (iguais? (cdr l1) (cdr l2)))
        (else #f)))

;; 7) Concatenação
(define (concatena l1 l2)
  (if (null? l1)
      l2
      (cons (car l1) (concatena (cdr l1) l2))))

;; 8) Intersecção (elementos de l1 que também estão em l2)
(define (intersecao l1 l2)
  (cond ((null? l1) '())
        ((membro? (car l1) l2)
         (cons (car l1) (intersecao (cdr l1) l2)))
        (else (intersecao (cdr l1) l2))))

;; Função para imprimir o nome e o resultado
(define (teste nome valor)
  (display nome)
  (display " => ")
  (write valor)
  (newline))

(teste "1) membro? 3 em (1 2 3)"        (membro? 3 '(1 2 3)))        ; #t
(teste "1) membro? 9 em (1 2 3)"        (membro? 9 '(1 2 3)))        ; #f
(teste "2) tamanho"                     (tamanho '(a b c d)))        ; 4
(teste "2) tamanho vazia"               (tamanho '()))               ; 0
(teste "3) soma"                        (soma '(1 2 3 4)))           ; 10
(teste "3) soma vazia"                  (soma '()))                  ; 0
(teste "4) produto"                     (produto '(1 2 3 4)))        ; 24
(teste "4) produto vazia"               (produto '()))               ; 1
(teste "5) reverso"                     (reverso '(1 2 3)))          ; (3 2 1)
(teste "6) iguais? (iguais)"            (iguais? '(1 2 3) '(1 2 3))) ; #t
(teste "6) iguais? (diferentes)"        (iguais? '(1 2 3) '(1 2 4))) ; #f
(teste "6) iguais? (tamanhos dif.)"     (iguais? '(1 2) '(1 2 3)))   ; #f
(teste "7) concatena"                   (concatena '(1 2) '(3 4)))   ; (1 2 3 4)
(teste "8) intersecao"                  (intersecao '(1 2 3 4) '(3 4 5))) ; (3 4)