const preorderDFS = (root, cb) => {
  if (root) {
    cb(root);
    if (root.left) cb(root.left);
    if (root.right) cb(root.right);
  }
}
