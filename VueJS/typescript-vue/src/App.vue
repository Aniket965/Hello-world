<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/retrotober.png">
    <br>
    <excited :name="name" :initialEnthusiasm="3"></excited>
    <br>
    <div class="container">
      <form class="form-inline">
        <div class="form-group">
          <h2>
            <label for="inputName" style="margin-right: 10px; margin-top: 4px;">Name:</label>
          </h2>
          <input
            v-model="name"
            type="text"
            class="form-control form-control"
            id="inputName"
            aria-describedby="emailHelp"
            placeholder="Enter name"
          >
        </div>
      </form>
    </div>
    <br>
    <hello-world msg="This is Your Vue.js + TypeScript App"/>
  </div>
</template>

<script lang="ts">
import { Component, Vue, Prop } from 'vue-property-decorator';
// import HelloWorld from './components/HelloWorld.vue';
import Excited from './components/Excited.vue'
import HelloWorld from './components/HelloWorld.vue'

@Component({
  data() {
    return {
      name: ""
    }
  },
  components: {
    Excited,
    HelloWorld
  }
})

export default class App extends Vue { }
</script>

<style>
#app {
	font-family: "Avenir", Helvetica, Arial, sans-serif;
	/* font- */
	-webkit-font-smoothing: antialiased;
	-moz-osx-font-smoothing: grayscale;
	text-align: center;
	color: #47b683;
}
.container {
	margin: auto;
	max-width: 275px;
}
</style>
