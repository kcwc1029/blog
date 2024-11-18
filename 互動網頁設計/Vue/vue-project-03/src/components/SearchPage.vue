<template>
    <p>這是search page</p>
    <p>搜尋關鍵字: {{ keyword }}</p>
</template>
<script setup>
import { useRoute } from "vue-router";

const route = useRoute();
const keyword = route.query.keyword;
console.log(keyword);
</script>
