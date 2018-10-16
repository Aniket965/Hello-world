const breadthFirstSearch = root => {
  let q = [root];
  while (q.length > 0) {
    let node = q.shift();
    q.push(node.left);
    q.push(node.right);
  }
}
