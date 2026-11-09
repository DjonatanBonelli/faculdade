-- Função para o método dos trapézios repetidos
trapz :: (Double -> Double) -> Double -> Double -> Int -> Double
trapz f a b n =
  let h = (b - a) / fromIntegral n
      xs = [a + h * fromIntegral i | i <- [1..n-1]]
      soma = sum (map f xs)
  in (h / 2) * (f a + 2 * soma + f b)

-- Função para o método de 1/3 de Simpson repetido
simpson :: (Double -> Double) -> Double -> Double -> Int -> Double
simpson f a b n
  | even n =
      let h = (b - a) / fromIntegral n
          xs1 = [a + h * fromIntegral i | i <- [1,3..n-1]]
          xs2 = [a + h * fromIntegral i | i <- [2,4..n-2]]
          soma1 = sum (map f xs1)
          soma2 = sum (map f xs2)
      in (h / 3) * (f a + 4 * soma1 + 2 * soma2 + f b)
  | otherwise = error "Simpson requer número par de subintervalos"

f x = x^2

main = do
  let a = 0
      b = 1
      n = 10
  print $ trapz f a b n
  print $ simpson f a b n 

-- ghci integracao.hs
-- main