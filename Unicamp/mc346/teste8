filter (\x -> isVowel toLower x ) xs

isVowel :: Char -> Bool
isVowel c = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 

geradicionario [] = []
geradicionario (x:xs) = soma1 x (geraDicionario xs)

vogalmaiscomum l = vogalmaiscomum' (geraDicionario (filter (\x -> isVowel toLower x ) l ) )
vogalmaiscomum' :: Ord a => [(t, a)] -> (t, a)
vogalmaiscomum' []     = 0
vogalmaiscomum' (x:xs) = maxTail x xs
  where maxTail currentMax [] = currentMax
        maxTail (m, n) (p:ps)
          | n < (snd p) = maxTail p ps
          | otherwise   = maxTail (m, n) ps