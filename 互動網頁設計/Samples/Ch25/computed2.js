Vue.createApp({ 
  data() {
    return {
      cm: 2.54
    }
  },
  computed: {
    inch: {
      get() {
	    return Number.parseFloat(Number(this.cm) / 2.54).toFixed(2);
	  },
	  set(val) {
	    this.cm = Number.parseFloat(Number(val) * 2.54).toFixed(2);
	  }
    }
  }
}).mount('#app');