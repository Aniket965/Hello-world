function BST(val) {
    this.val = val;
    this.left = null;
    this.right = null;
}

BST.prototype.add = function (val) {
    let curr = this;
    const newNode = new BST(val);
    while (curr) {
        if (val >= curr.val) {
            // traverse right
            if (!curr.right) {
                curr.right = newNode;
                return; // function ends
            }
            curr = curr.right
        } else {
            //traverse left
            if (!curr.left) {
                curr.left = newNode;
                return;
            }
            curr = curr.left;
        }
    }
}