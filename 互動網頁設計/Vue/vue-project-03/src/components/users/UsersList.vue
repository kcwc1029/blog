<template>
    <p>這是UserList</p>
    <p>{{ userId }}</p>
</template>
<script setup>
import { useRoute } from "vue-router";

// 使用 useRoute() 來取得 params
const route = useRoute();
const userId = route.params.userID;

// 確認是否成功取得 userID
console.log("User ID:", userId);
</script>
