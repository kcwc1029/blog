<template>
    <div>
        <h2>Manage Goals</h2>
        <p>這裡是 Manage Goals 的內容。</p>

        <input type="text" ref="goalInput" />
        <button @click="setGoal">Set Goal</button>
    </div>
</template>

<script>
export default {
    methods: {
        setGoal() {
            const enteredValue = this.$refs.goalInput.value;
            if (!enteredValue.trim()) {
                alert("請輸入目標");
            } else {
                console.log("設定的目標:", enteredValue);
            }
        },
    },
};
</script>
