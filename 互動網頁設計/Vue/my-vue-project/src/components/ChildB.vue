<template>
    <div>
        <h4>子元件 B</h4>
        <child-c />
    </div>
</template>

<script>
import ChildC from "./ChildC.vue";

export default {
    components: { ChildC },
};
</script>
