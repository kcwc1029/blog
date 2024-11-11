<template>
    <li class="card mb-3 shadow border-0">
        <div class="card-body text-center">
            <!-- 顯示朋友名稱 -->
            <h2 class="card-title h4 text-primary">{{ friend.name }}</h2>
            <!-- 切換顯示詳細資料的按鈕 -->
            <button class="btn btn-danger mb-2" @click="toggleDetails">
                {{ detailAreVisible ? "Hide Details" : "Show Details" }}
            </button>
            <!-- 子元件傳遞父元件 -->
            <button class="btn btn-warning mb-2" @click="editFriend">更新資料</button>

            <!-- 刪除資料 -->
            <button class="btn btn-info mb-2" @click="deleteFriend">刪除資料</button>
            <!-- 顯示詳細資料 -->
            <ul v-if="detailAreVisible" class="list-group list-group-flush">
                <li class="list-group-item border border-2 shadow"><strong>Phone:</strong> {{ friend.phone }}</li>
                <li class="list-group-item border border-2 shadow"><strong>Email:</strong> {{ friend.email }}</li>
            </ul>
        </div>
    </li>
</template>

<script>
export default {
    props: {
        friend: {
            type: Object, //
            required: true,
            // NOTE: props驗證
            // default:"",
            // validator: () => {},
        },
    },
    data() {
        return {
            detailAreVisible: false,
        };
    },
    methods: {
        toggleDetails() {
            this.detailAreVisible = !this.detailAreVisible;
        },
        editFriend() {
            // TODO: 使用 $emit 發送事件，並傳遞 friend.id 給父元件
            this.$emit("update-friend", this.friend.id);
        },
        deleteFriend() {
            this.$emit("delete-friend", this.friend.id);
        },
    },
};
</script>
