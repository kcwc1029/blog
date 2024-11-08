<template>
    <h1 class="display-3">哥布林清單</h1>
    <section>
        <ul>
            <li>{{ goblin.id }}</li>
            <li>{{ goblin.name }}</li>
            <li>{{ goblin.phone }}</li>
            <li>{{ goblin.email }}</li>
            <friend-card></friend-card>
            <friend-card></friend-card>
        </ul>
    </section>
</template>

<script>
export default {
    name: "App",
    data() {
        return {
            goblin: {
                id: "001",
                name: "助教哥布林1號",
                phone: "7777777777",
                email: "7777777777@gmail.com",
            },
        };
    },
    methods: {},
    computed: {},
};
</script>

<style></style>
