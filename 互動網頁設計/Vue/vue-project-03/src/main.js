import { createApp } from "vue";
import { createRouter, createMemoryHistory } from "vue-router";

import App from "./App.vue";
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.bundle.min.js";
import TeamsList from "./components/teams/TeamsList.vue";
import UsersList from "./components/users/UsersList.vue";

const router = createRouter({
    history: createMemoryHistory(),
    routes: [
        { path: "/", redirect: "/teams" }, // 根路徑自動重導向到 /teams
        { path: "/teams", component: TeamsList },
        { path: "/users", component: UsersList },
    ],
});
const app = createApp(App);
app.use(router);
app.mount("#app");
