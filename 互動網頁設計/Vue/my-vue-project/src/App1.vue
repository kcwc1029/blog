<template>
    <div class="container">
        <h2>父元件 (App)</h2>
        <p>來自深層子元件的資料：{{ sharedData }}</p>
        <child-a />
    </div>
</template>

<script>
import { provide, ref } from "vue";
import ChildA from "./ChildA.vue";

export default {
    components: { ChildA },
    setup() {
        // 定義要提供的資料
        const sharedData = ref("父元件初始資料");

        // 提供資料和更新方法給子元件
        provide("sharedData", sharedData);

        return { sharedData };
    },
};
</script>
