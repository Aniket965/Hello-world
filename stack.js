class Stack {
  constructor () {
    this.s = [];
  }

  peek () {
    return this.s[this.s.length - 1];
  }

  pop () {
    return this.s.pop();
  }

  push (val) {
    this.s.push(val);
    return this.s.length;
  }

  size () {
    return this.s.length;
  }

  isEmpty () {
    return this.s.length === 0;
  }
}

export default Stack
