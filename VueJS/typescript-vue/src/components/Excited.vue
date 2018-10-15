<template>
    <div>
        <h2>
            <div class="greeting">Hello! Welcome {{name}}{{exclamationMarks}}</div>
        </h2>
        <button class="btn btn-outline-info" @click="decrement" style="margin-right: 10px">-</button>
        <button class="btn btn-outline-info" @click="increment" style="margin-left: 10px">+</button>
    </div>
</template>

<script lang="ts">
// import Vue from 'vue';
import { Vue, Component, Prop } from "vue-property-decorator";

@Component
export default class Excited extends Vue {
    @Prop() name!: string;
    @Prop() initialEnthusiasm!: number;

    enthusiasm = this.initialEnthusiasm;

    increment() {
        this.enthusiasm++;
    }
    decrement() {
        if (this.enthusiasm > 1) {
            this.enthusiasm--;
        }
    }

    get exclamationMarks(): string {
        return Array(this.enthusiasm + 1).join('!');
    }
}

// export default Vue.extend({
//     props: ['name', 'initialEnthusiasm'],
//     data(): any {
//         return {
//             enthusiasm: this.initialEnthusiasm
//         }
//     },
//     methods: {
//         increment() {
//             this.enthusiasm++
//         },
//         decrement() {
//             if (this.enthusiasm > 1) {
//                 this.enthusiasm--
//             }
//         },
//     },
//     computed:  {
//         exclamationMarks(): string {
//             return Array(this.enthusiasm + 1).join('!')
//         }
//     }
// })
</script>

<style>
.greeting {
	font-size: 2em;
}
/* button {
	height: 2em;
	width: 2em;
} */
</style>
