class Queue {
  constructor () {
    this.q = [];
  }

  peek () {
    return this.q[0];
  }

  pop () {
    return this.q.shift();
  }

  push (val) {
    this.q.push(val);
    return this.q.length;
  }

  size () {
    return this.q.length;
  }

  isEmpty () {
    return this.q.length === 0;
  }
}

export default Queue
