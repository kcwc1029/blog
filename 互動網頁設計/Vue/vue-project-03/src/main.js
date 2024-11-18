import { createApp } from "vue";
import { createPinia } from "pinia";
import { createRouter, createWebHistory } from "vue-router";

import App from "./App.vue";
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.bundle.min.js";
import TeamsList from "./components/teams/TeamsList.vue";
import TeamsFooter from "./components/teams/TeamsFooter.vue";
import UsersList from "./components/users/UsersList.vue";
import UsersFooter from "./components/users/UsersFooter.vue";
import SearchPage from "./components/SearchPage.vue";
import TheAbout from "./components/about/TheAbout.vue";

const router = createRouter({
    history: createWebHistory(),
    routes: [
        { path: "/", redirect: "/teams" },
        { path: "/search", component: SearchPage },
        // 一次渲染多個component
        {
            name: "teams",
            path: "/teams",
            components: { default: TeamsList, footer: TeamsFooter },
        },
        {
            name: "users",
            path: "/users",
            components: { default: UsersList, footer: UsersFooter },
        },
        {
            path: "/about",
            component: TheAbout,
        },
        // 捕獲所有路徑 -> 可以接404 NOT FOUND
        { path: "/:pathMatch(.*)*", component: TeamsList },
    ],
    linkActiveClass: `router-link-active`,
    scrollBehavior(to, from, savedPosition) {
        if (savedPosition) {
            return savedPosition;
        } else if (to.hash) {
            return {
                el: to.hash,
                behavior: "smooth",
            };
        } else {
            return { top: 0, behavior: "smooth" };
        }
    },
});
const pinia = createPinia();
const app = createApp(App);
app.use(router);
app.use(pinia);
app.mount("#app");
