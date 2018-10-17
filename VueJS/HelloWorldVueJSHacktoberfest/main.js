Vue.component('hello-world', {
    props: ['hello'],
    template: '<h1>{{ hello.text }}</h1>'
})

let app = new Vue({
    el: '#app',
    data: {
        helloList: [
            { id: 0, text: 'Hello World!' },
            { id: 1, text: 'Hacktoberfest 2018!'}
        ]
    }
  })