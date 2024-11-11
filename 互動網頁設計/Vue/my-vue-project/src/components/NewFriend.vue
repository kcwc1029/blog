<template>
    <form @submit.prevent="submitData" class="container mt-4 p-4 border rounded shadow">
        <!-- 姓名輸入欄位 -->
        <div class="mb-3">
            <label for="name" class="form-label">Name</label>
            <input type="text" class="form-control" id="name" placeholder="Enter name" v-model="enterName" />
        </div>

        <!-- 電話輸入欄位 -->
        <div class="mb-3">
            <label for="phone" class="form-label">Phone</label>
            <input type="text" class="form-control" id="phone" placeholder="Enter phone number" v-model="enterPhone" />
        </div>

        <!-- 電子郵件輸入欄位 -->
        <div class="mb-3">
            <label for="email" class="form-label">Email</label>
            <input type="email" class="form-control" id="email" placeholder="Enter email" v-model="enterEmail" />
        </div>

        <!-- 提交按鈕 -->
        <div class="d-grid">
            <button type="submit" class="btn btn-primary">Add Contact</button>
        </div>
    </form>
</template>

<script>
export default {
    emits: [],
    data() {
        return {
            enterName: "",
            enterPhone: "",
            enterEmail: "",
        };
    },
    methods: {
        submitData() {
            this.$emit("add-content", this.enterName, this.enterPhone, this.enterEmail);
        },
    },
};
</script>

<style></style>
