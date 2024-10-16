Vue.createApp({
  data() {
    return {
      height: 0,
	  weight: 0,
	  BMI: 0
    }
  },
  methods: {
    evalBMI() {	  
	  this.BMI = (this.weight / (this.height / 100) ** 2).toFixed(2);
	}
  }
}).mount('#app');
