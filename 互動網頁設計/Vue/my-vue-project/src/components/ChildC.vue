<template>
    <div>
        <h5>子元件 C</h5>
        <p>目前的資料：{{ sharedData }}</p>
        <input type="text" v-model="sharedData" class="form-control" />
        <button @click="clearData" class="btn btn-danger mt-2">清除資料</button>
    </div>
</template>

<script>
import { inject } from "vue";

export default {
    setup() {
        // 注入父元件提供的資料
        const sharedData = inject("sharedData");

        // 方法：清除資料
        const clearData = () => {
            sharedData.value = ""; // 修改注入的資料，會同步反映在父元件
        };

        return { sharedData, clearData };
    },
};
</script>
