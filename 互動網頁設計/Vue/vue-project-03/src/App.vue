<template>
    <!-- 導覽列 => TheNavigation.vue -->
    <the-navigation></the-navigation>
    <!-- 吃router的defaule -->
    <router-view></router-view>
    <!-- 吃router的footer -->
    <router-view name="footer"></router-view>
</template>

<script setup>
import TheNavigation from "./components/nav/TheNavigation.vue";
</script>

<style></style>
