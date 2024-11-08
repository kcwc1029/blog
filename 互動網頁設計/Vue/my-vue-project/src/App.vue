<template>
    <h2 class="display-5 text-center">助教清單</h2>
    <!-- TODO: component -->
    <section>
        <ul>
            <friend-contact></friend-contact>
            <friend-contact></friend-contact>
            <friend-contact></friend-contact>
        </ul>
    </section>
</template>

<script>
export default {
    data() {
        return {
            friends: [
                { id: "001", name: "吉伊卡哇", phone: "77777777", email: "77777777@gmail.com" },
                { id: "002", name: "小八貓", phone: "88888888", email: "88888888@gmail.com" },
                { id: "003", name: "兔兔", phone: "88888888", email: "88888888@gmail.com" },
                { id: "004", name: "小桃鼠   ", phone: "88888888", email: "88888888@gmail.com" },
            ],
        };
    },
    methods: {},
    computed: {},
};
</script>

<style></style>
