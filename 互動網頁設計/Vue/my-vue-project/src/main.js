import { createApp } from "vue";
import App from "./App.vue";

// TODO: bt5
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap";

// TODO: component
import FriendContact from "./components/FriendContact.vue";
import NewFriend from "./components/NewFriend.vue";

const app = createApp(App);
app.component("friend-contact", FriendContact);
app.component("new-friend", NewFriend);
app.mount("#app");
