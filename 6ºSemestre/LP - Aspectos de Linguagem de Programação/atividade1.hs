-- 1) Testar se um elemento é membro de uma lista
-- 2) Calcular o tamanho de uma lista
-- 3) Calcular a soma dos elementos de uma lista
-- 4) Calcular o produto dos elementos de uma lista
-- 5) Reversão de lista
-- 6) Testar se duas listas são iguais
-- 7) Concatenação de duas listas
-- 8) Intersecção de duas listas

-- Para rodar: runghc atividade1.hs


-- 1) Membro de lista
membro :: Eq a => a -> [a] -> Bool
membro _ [] = False
membro x (y:ys) = x == y || membro x ys

-- 2) Tamanho
tamanho :: [a] -> Int
tamanho [] = 0
tamanho (_:xs) = 1 + tamanho xs

-- 3) Soma
soma :: Num a => [a] -> a
soma [] = 0
soma (x:xs) = x + soma xs

-- 4) Produto
produto :: Num a => [a] -> a
produto [] = 1
produto (x:xs) = x * produto xs

-- 5) Reversão (com acumulador, O(n))
reverso :: [a] -> [a]
reverso xs = aux xs []
  where
    aux [] acc = acc
    aux (y:ys) acc = aux ys (y:acc)

-- 6) Igualdade de listas
iguais :: Eq a => [a] -> [a] -> Bool
iguais [] [] = True
iguais [] _ = False
iguais _ [] = False
iguais (x:xs) (y:ys) = x == y && iguais xs ys

-- 7) Concatenação
concatena :: [a] -> [a] -> [a]
concatena [] ys = ys
concatena (x:xs) ys = x : concatena xs ys

-- 8) Intersecção (elementos de xs que também estão em ys)
intersecao :: Eq a => [a] -> [a] -> [a]
intersecao [] _ = []
intersecao (x:xs) ys
  | membro x ys = x : intersecao xs ys
  | otherwise = intersecao xs ys

-- Função main para rodar os testes
main :: IO ()
main = do
  putStrLn "1) membro"
  print (membro 3 [1,2,3]) -- True
  print (membro 9 [1,2,3]) -- False

  putStrLn "2) tamanho"
  print (tamanho [10,20,30,40]) -- 4
  print (tamanho ([] :: [Int])) -- 0

  putStrLn "3) soma"
  print (soma [1,2,3,4]) -- 10
  print (soma ([] :: [Int])) -- 0

  putStrLn "4) produto"
  print (produto [1,2,3,4]) -- 24
  print (produto ([] :: [Int])) -- 1

  putStrLn "5) reverso"
  print (reverso [1,2,3]) -- [3,2,1]

  putStrLn "6) iguais"
  print (iguais [1,2,3] [1,2,3]) -- True
  print (iguais [1,2,3] [1,2,4]) -- False
  print (iguais [1,2] [1,2,3]) -- False

  putStrLn "7) concatena"
  print (concatena [1,2] [3,4]) -- [1,2,3,4]

  putStrLn "8) intersecao"
  print (intersecao [1,2,3,4] [3,4,5]) -- [3,4]