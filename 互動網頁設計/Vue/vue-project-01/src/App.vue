<template>
    <div>
        <the-header></the-header>
        <badge-list></badge-list>
        <user-info :full-name="activeUser.name" :info-text="activeUser.description" :role="activeUser.role"></user-info>
        <!-- 使用單一按鈕進行切換 -->
        <button @click="toggleComponent">切換動態元件按鈕</button>
        <!-- 動態元件渲染 -->
        <component :is="selectedComponent"></component>
    </div>
</template>

<script>
import TheHeader from "./components/TheHeader.vue";
import BadgeList from "./components/BadgeList.vue";
import UserInfo from "./components/UserInfo.vue";
import ActiveGoals from "./components/ActiveGoals";
import ManageGoals from "./components/ManageGoals.vue";

export default {
    name: "App",
    // NOTE:
    // Vue 在使用組件時，會自動將 PascalCase 名稱 (TheHeader)
    // 轉換成 kebab-case (the-header)。
    components: {
        TheHeader,
        BadgeList,
        UserInfo,
        ActiveGoals,
        ManageGoals,
    },
    data() {
        return {
            activeUser: {
                name: "Maximilian Schwarzmüller",
                description: "Site owner and admin",
                role: "admin",
            },
            selectedComponent: "ActiveGoals", // 預設顯示 ActiveGoals
        };
    },
    computed: {
        // 根據當前顯示的元件設定按鈕文字
        buttonText() {
            return this.selectedComponent === "ActiveGoals" ? "Switch to Manage Goals" : "Switch to Active Goals";
        },
    },
    methods: {
        toggleComponent() {
            // 切換顯示的元件
            this.selectedComponent = this.selectedComponent === "ActiveGoals" ? "ManageGoals" : "ActiveGoals";
        },
    },
};
</script>

<style></style>
