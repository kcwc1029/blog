import { defineStore } from "pinia";
import { ref } from "vue";
import axios from "axios";

export const usePokemonStore = defineStore("pokemonStore", () => {
    // state
    const pokemon = ref(null);
    const isLoading = ref(false);
    const error = ref(null);

    // 非同步函數來獲取寶可夢資料
    const fetchPokemon = async (name) => {
        isLoading.value = true;
        error.value = null;
        try {
            // 發送 API 請求
            const response = await axios.get(`https://pokeapi.co/api/v2/pokemon/${name}`);
            pokemon.value = response.data;
        } catch (e) {
            error.value = "找不到該寶可夢!";
            console.error(e);
        } finally {
            isLoading.value = false;
        }
    };
    return { pokemon, isLoading, error, fetchPokemon };
});
