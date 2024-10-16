Vue.createApp({
  data() {
    return {
      height: 160,
	  weight: 45
    }
  },
  methods: {
    BMI() {	  
	  return (this.weight / (this.height / 100) ** 2).toFixed(2);
	}
  }
}).mount('#app');