data Tree a = Vazia | No a (Tree a) (Tree a)

inserelista :: (Ord a, Eq a) => [a] -> Tree a
inserelista (x:xs) = insere x (insere xs) 


insere :: Int -> Tree -> Tree
insere x Tree = No x Tree Tree
insere x (No i t1 t2)  
          | x <= i    = No i (insere x t1)  t2
          | otherwise = No i  t1           (insere x t2)