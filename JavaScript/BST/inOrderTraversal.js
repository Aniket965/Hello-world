function inOrder(tree) { // prints contents of tree in numberical order
    if (tree) {
        inOrder(tree.left);
        console.log(tree.val);
        inOrder(tree.right);
    }
}