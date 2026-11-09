module Raizes where  -- Define um módulo para carregar no GHCi

-- Método da Bissecção
bisseccao :: (Double -> Double) -> Double -> Double -> Double -> Double
bisseccao f a b epsilon
    | f a * f b >= 0 = error "A função deve ter sinais opostos em a e b."
    | (b - a) < epsilon = (a + b) / 2
    | f a * f x > 0 = bisseccao f x b epsilon
    | otherwise = bisseccao f a x epsilon
  where
    x = (a + b) / 2

-- Método da Posição Falsa
posicaoFalsa :: (Double -> Double) -> Double -> Double -> Double -> Double -> Double
posicaoFalsa f a b epsilon1 epsilon2
    | f a * f b >= 0 = error "A função deve ter sinais opostos em a e b."
    | (b - a) < epsilon1 = (a + b) / 2
    | abs (f x) < epsilon2 = x
    | f a * f x > 0 = posicaoFalsa f x b epsilon1 epsilon2
    | otherwise = posicaoFalsa f a x epsilon1 epsilon2
  where
    x = (a * f b - b * f a) / (f b - f a)

-- Método do Ponto Fixo
pontoFixo :: (Double -> Double) -> (Double -> Double) -> Double -> Double -> Double -> Double
pontoFixo f phi x0 epsilon1 epsilon2
    | abs (f x1) < epsilon1 || abs (x1 - x0) < epsilon2 = x1
    | otherwise = pontoFixo f phi x1 epsilon1 epsilon2
  where
    x1 = phi x0

-- Função de exemplo: f(x) = x^3 - x - 2
f :: Double -> Double
f x = x**3 - x - 2

-- Transformação para o Método do Ponto Fixo
phi :: Double -> Double
phi x = (x + 2) ** (1/3)
