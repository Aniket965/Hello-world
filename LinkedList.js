class LinkedList {
  constructor (val) {
    this.value = val;
    this.n = null;
  }

  set next (node) {
    this.n = node;
  }

  set val (val) {
    this.value = val;
  }

  get next () {
    return this.n;
  }

  get val () {
    return this.value;
  }
}

export default LinkedList;
