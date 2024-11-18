import { defineStore } from "pinia";
import { ref, computed } from "vue";

// 定義 Pinia Store
export const useAlertsStore = defineStore("counter", () => {
    const count = ref(0);
    const name = ref("TA");

    // 使用 computed 來建立計算屬性
    const doubleCount = computed(() => count.value * 2);

    // 定義方法
    const increment = () => {
        count.value++;
    };

    return { count, name, doubleCount, increment };
});
