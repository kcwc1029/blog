<template>
    <div class="container mt-5">
        <form @submit.prevent="saveData" class="p-4 border rounded shadow">
            <!-- Name Input -->
            <div class="mb-3">
                <label for="name" class="form-label">Your Name</label>
                <input type="text" id="name" v-model="formData.name" @blur="validInput" class="form-control" />
                <div v-if="formData.namevalid === 'invalid'" class="text-danger mt-1">請輸入有效username</div>
            </div>

            <!-- Age Input -->
            <div class="mb-3">
                <label for="age" class="form-label">Your Age (Years)</label>
                <input type="number" id="age" v-model.number="formData.age" class="form-control" />
            </div>

            <!-- Dropdown: How did you hear about us? -->
            <div class="mb-3">
                <label for="source" class="form-label">How did you hear about us?</label>
                <select id="source" v-model="formData.source" class="form-select">
                    <option value="Google">Google</option>
                    <option value="Friend">Friend</option>
                    <option value="Advertisement">Advertisement</option>
                </select>
            </div>

            <!-- Checkbox Group: Interests -->
            <div class="mb-3">
                <label class="form-label">What are you interested in?</label>
                <div class="form-check">
                    <input type="checkbox" id="news" value="News" v-model="formData.interests" class="form-check-input" />
                    <label for="news" class="form-check-label">News</label>
                </div>
                <div class="form-check">
                    <input type="checkbox" id="tutorials" value="Tutorials" v-model="formData.interests" class="form-check-input" />
                    <label for="tutorials" class="form-check-label">Tutorials</label>
                </div>
                <div class="form-check">
                    <input type="checkbox" id="nothing" value="Nothing" v-model="formData.interests" class="form-check-input" />
                    <label for="nothing" class="form-check-label">Nothing</label>
                </div>
            </div>

            <!-- Radio Buttons: How do you learn? -->
            <div class="mb-3">
                <label class="form-label">How do you learn?</label>
                <div class="form-check">
                    <input type="radio" id="video" value="Video Courses" v-model="formData.learningMethod" class="form-check-input" />
                    <label for="video" class="form-check-label">Video Courses</label>
                </div>
                <div class="form-check">
                    <input type="radio" id="blogs" value="Blogs" v-model="formData.learningMethod" class="form-check-input" />
                    <label for="blogs" class="form-check-label">Blogs</label>
                </div>
                <div class="form-check">
                    <input type="radio" id="other" value="Other" v-model="formData.learningMethod" class="form-check-input" />
                    <label for="other" class="form-check-label">Other</label>
                </div>
            </div>

            <!-- Submit Button -->
            <button type="submit" class="btn btn-primary w-100">Save Data</button>
        </form>
        <button @click="loadData" type="submit" class="btn btn-success w-100">load Data</button>
    </div>
</template>

<script setup>
import { onMounted, reactive, ref } from "vue";
const loadedData = ref([]);
const formData = reactive({
    name: "",
    age: 0,
    source: "Google",
    interests: [],
    learningMethod: "Video Courses",
    namevalid: "",
});

const validInput = () => {
    if (formData.name === "") formData.namevalid = "invalid";
    else formData.namevalid = "valid";
    console.log(formData.namevalid);
};

fetch("https://vue-http-demo-f3460-default-rtdb.firebaseio.com/" + "surveys.json", {
    method: "POST",
});

// TODO: 發送表單資料到 Firebase 的函數
const saveData = async () => {
    // 檢查表單是否已填寫
    if (formData.name === "" || formData.age === 0) {
        alert("請填寫所有必填欄位");
        return;
    }
    try {
        const response = await fetch("https://vue-http-demo-f3460-default-rtdb.firebaseio.com/surveys.json", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify(formData),
        });
        if (!response.ok) throw new Error("發送資料失敗！");

        const data = await response.json();
        console.log("表單資料已成功送出", data);
    } catch (e) {
        console.log("錯誤", e);
        alert("發送資料失敗，請稍後再試。");
    }
};

const loading = ref(false); // 使用 ref 來定義 flag

// 從 Firebase 讀取資料
const loadData = async () => {
    loading.value = true; // 載入loading顯示
    try {
        const response = await fetch("https://vue-http-demo-f3460-default-rtdb.firebaseio.com/surveys.json", {
            method: "GET",
            headers: { "Content-Type": "application/json" },
        });
        if (!response.ok) throw new Error("讀取資料失敗！");

        const data = await response.json();
        if (data) {
            // 確保使用 .value 來更新 ref
            loadedData.value = Object.values(data);
            console.log("已載入資料", loadedData.value);
        } else console.log("無資料可載入");
        loading.value = false; // 取消loading顯示
    } catch (error) {
        console.error("錯誤", error);
        alert("讀取資料失敗，請稍後再試。");
    }
};

// 使用 onMounted 正確載入資料
onMounted(() => {
    loadData();
});
</script>

<style scoped></style>
