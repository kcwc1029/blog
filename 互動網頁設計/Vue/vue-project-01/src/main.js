import { createApp } from "vue";
import App from "./App.vue";
import BaseBadge from "./components/BaseBadge.vue";

import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.bundle.min.js";

const app = createApp(App);

// NOTE: global component
// 他是一個小徽章，大家都要用 => 放global
app.component("base-badge", BaseBadge);

app.mount("#app");
