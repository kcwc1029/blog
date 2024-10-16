Vue.createApp({
  data() {
    return {
      fgColor: 'blue',
	  bgColor: 'white'
    }
  },
  methods: {
    change() {	  
	  this.fgColor = 'white';
	  this.bgColor = 'red';
	},
	restore() {
	  this.fgColor = 'blue';
	  this.bgColor = 'white';
	}
  }
}).mount('#app');
