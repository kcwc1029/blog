<template>
    <the-form></the-form>
</template>

<script>
import TheForm from "./components/TheForm";

export default {
    name: "App",
    components: {
        TheForm,
    },
};

// x是在內部使用，但在外部卻可以使用
// => 這樣很可怕
if (true) {
    var x = 10;
}
console.log(x); // 輸出: 10
</script>

<style></style>
