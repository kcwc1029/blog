<template>
    <!-- 導覽列 => TheNavigation.vue -->
    <the-navigation></the-navigation>
    <!-- 吃router的defaule -->
    <router-view></router-view>
    <!-- 吃router的footer -->
    <router-view name="footer"></router-view>
    <p>{{ store.name }}</p>
    <p>{{ store.count }}</p>
    <p>使用getter乘2：{{ store.doubleCount }}</p>
    <ul>
        <li v-for="task in store.tasks" :key="task.id">
            <label for="">
                <input type="checkbox" name="" id="" v-model="task.isCompleted" @change="store.toggleTaskCompletion(task.id)" />
                <span>{{ task.title }}</span>
            </label>
            <button @click="store.removeTask(task.id)">delete</button>
        </li>
    </ul>
    <!-- 使用action -->
    <div>
        <h1>寶可夢查詢器</h1>
        <input v-model="pokemonName" placeholder="輸入寶可夢名稱" />
        <button @click="searchPokemon">查詢</button>

        <div v-if="pokemonStore.isLoading">載入中...</div>
        <div v-if="pokemonStore.error">{{ pokemonStore.error }}</div>

        <div v-if="pokemonStore.pokemon && !pokemonStore.isLoading">
            <h2>{{ pokemonStore.pokemon.name }}</h2>
            <img :src="pokemonStore.pokemon.sprites.front_default" alt="寶可夢圖片" />
            <p>編號: #{{ pokemonStore.pokemon.id }}</p>
            <p>體重: {{ pokemonStore.pokemon.weight }} 公斤</p>
            <p>高度: {{ pokemonStore.pokemon.height }} 公尺</p>
        </div>
    </div>
    <div>
        <h1>{{ name }}</h1>
        <p>Count: {{ count }}</p>
        <p>Double Count: {{ doubleCount }}</p>
        <button @click="increment">Increment</button>
    </div>
</template>

<script setup>
import { ref } from "vue";
import { storeToRefs } from "pinia";
import TheNavigation from "./components/nav/TheNavigation.vue";
import { useAlertsStore } from "./components/stores/TaskStore.js";
import { usePokemonStore } from "./components/stores/PokemonStore.js";
const store = useAlertsStore(); // 取得任務管理的 Pinia store
// 使用 storeToRefs 來解構 Store 的 state 和 getters
const { count, name, doubleCount } = storeToRefs(store);
// 可以直接調用 actions
const { increment } = store;

const pokemonStore = usePokemonStore(); // 取得寶可夢管理的 Pinia store
const pokemonName = ref("");
const searchPokemon = async () => {
    if (pokemonName.value) {
        await pokemonStore.fetchPokemon(pokemonName.value.toLowerCase());
    }
};
</script>

<style></style>
