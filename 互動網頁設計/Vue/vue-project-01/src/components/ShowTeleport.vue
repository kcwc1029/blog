<template>
    <div>
        <h1>主內容區域</h1>
        <button @click="showModal = true">顯示彈出視窗</button>

        <!-- TODO: 使用 Teleport 將內容移動到 body -->
        <!-- 將內部的內容渲染到 <body> 標籤中，而不是原本的父容器內。 -->
        <teleport to="body">
            <div v-if="showModal" class="modal">
                <p>這是一個彈出視窗</p>
                <button @click="showModal = false">關閉</button>
            </div>
        </teleport>
    </div>
</template>

<script setup>
import { ref } from "vue";

const showModal = ref(false);
</script>

<style>
.modal {
    position: fixed;
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
    background-color: white;
    padding: 20px;
    box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
    z-index: 1000;
}
</style>
