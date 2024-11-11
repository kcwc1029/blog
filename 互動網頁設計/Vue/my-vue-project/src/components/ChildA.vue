<template>
    <div>
        <h3>子元件 A</h3>
        <child-b />
    </div>
</template>

<script>
import ChildB from "./ChildB.vue";

export default {
    components: { ChildB },
};
</script>
