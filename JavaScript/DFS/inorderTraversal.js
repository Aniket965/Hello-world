const inorderDFS = (root, cb) => {
  if (root) {
    if (root.left) cb(root.left);
    cb(root);
    if (root.right) cb(root.right);
  }
}
