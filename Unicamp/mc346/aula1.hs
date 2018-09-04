sumEvenIndexes :: (Num a) => [a] -> a
sumEvenIndexes [] = 0
sumEvenIndexes (x:xs) = (sumEvenIndexes' 1 (x:xs))

sumEvenIndexes' :: (Eq a, Num a) => a -> [a] -> a
sumEvenIndexes' _ [] = 0
sumEvenIndexes' n (x:xs) = (if (mod n 2) == 0 then x + (sumEvenIndexes' n+1 xs) else (sumEvenIndexes' n+1 xs))
