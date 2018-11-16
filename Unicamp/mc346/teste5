import Data.List.Split
main = do
		contents <- getContents
		putStr (ponderada (parseLinha (splitOn " " contents)))

parseLinha :: [String] -> [Int]
parseLinha = map read

ponderada :: [a] -> Num
ponderada [] = 0
ponderada (x:y:xs) = 
				let n/w   
				where 
						n = x*y + ponderada xs
						w = y + ponderada xs 
