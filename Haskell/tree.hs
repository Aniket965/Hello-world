data Tree a = Leaf | Node a (Tree a) (Tree a) deriving (Show)

insertNode :: (Ord a) => a -> Tree a -> Tree a
insertNode x Leaf = Node x Leaf Leaf 
insertNode x (Node a left rigth)
    | x < a = Node a (insertNode x left) rigth
    | x > a = Node a left (insertNode x rigth)
    | otherwise = Node a left rigth

makeTree :: (Foldable t, Ord a) => t a -> Tree a
makeTree = foldl (\acc x -> insertNode x acc) Leaf

preOrder :: Tree t -> [t]
preOrder Leaf = []
preOrder (Node x left rigth) = [x] ++ preOrder left ++ preOrder rigth

inOrder :: Tree t -> [t]
inOrder Leaf = []
inOrder (Node x left rigth) = inOrder left ++ [x] ++ inOrder rigth

postOrder :: Tree t -> [t]
postOrder Leaf = []
postOrder (Node x left rigth) = postOrder left ++ postOrder rigth ++ [x]