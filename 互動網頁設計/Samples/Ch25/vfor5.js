Vue.createApp({
  data() {
    return {
      numbers: [1, 2, 3, 4, 5]
    }
  },
  methods: {
    even(numbers) {
      return this.numbers.filter(n => n % 2 === 0)
    }
  }
}).mount('#app');