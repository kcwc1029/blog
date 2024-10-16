Vue.createApp({
  data() {
    return {
      isOne: true,
	  isTwo: false
    }
  },
  methods: {
    change() {	  
	  this.isOne = false;
	  this.isTwo = true;
	},
	restore() {
	  this.isOne = true;
	  this.isTwo = false;
	}
  }
}).mount('#app');
