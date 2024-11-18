<template>
    <p>這是TeamList</p>
    <button @click="confirmInput">切換到user</button>
</template>
<script setup>
import { useRouter } from "vue-router";
const router = useRouter();

const confirmInput = () => {
    router.push("/users");
};
</script>
