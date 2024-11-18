import { defineStore } from "pinia";
import { ref, reactive, computed } from "vue";

// 定義 Pinia Store
export const useAlertsStore = defineStore("counter", () => {
    // TODO: state
    const count = ref(1);
    const name = ref("TA");
    const tasks = reactive([
        {
            id: 1,
            title: "TA1",
            isCompleted: false,
        },
        {
            id: 2,
            title: "TA2",
            isCompleted: true,
        },
        {
            id: 3,
            title: "TA3",
            isCompleted: true,
        },
    ]);

    // TODO: getters
    const addTask = (title) => {
        tasks.push({
            id: tasks.length + 1,
            title: title,
            isCompleted: false,
        });
    };
    const toggleTaskCompletion = (id) => {
        const task = tasks.find((task) => task.id === id);
        console.log("被toggle", task);
    };

    const removeTask = (id) => {
        const index = tasks.findIndex((task) => task.id === id);
        if (index !== -1) tasks.splice(index, 1); // 刪除1個元素
    };
    // TODO: getters
    const doubleCount = computed(() => count.value * 2);
    const increment = () => {
        count.value++;
    };
    return { name, tasks, count, doubleCount, increment, addTask, removeTask, toggleTaskCompletion };
});
