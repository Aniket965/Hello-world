var app = new Vue({
  el: '#app',
  data: {
    seen: false
  },
  methods: {
    toggle() {
      this.seen = !this.seen;
    },
  },
})
