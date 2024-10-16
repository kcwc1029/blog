Vue.createApp({
  data() {
    return {
      height: 160,
	  weight: 45
    }
  },
  computed: {
    BMI() {	  
	  return (this.weight / (this.height / 100) ** 2).toFixed(2);
	}
  }
}).mount('#app');