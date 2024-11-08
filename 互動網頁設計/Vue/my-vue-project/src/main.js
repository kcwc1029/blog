import { createApp } from "vue";
import App from "./App.vue";

// TODO: bt5
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap";

// TODO: component
import FriendContact from "./components/FriendContact.vue";
const app = createApp(App);
app.component("friend-contact", FriendContact);
app.mount("#app");
