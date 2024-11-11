<template>
    <!-- NOTE: [vue/no-multiple-template-root] The template root requires exactly one element -->
    <!-- template裡面要放一個根元素(div或section) -->
    <section>
        <h2 class="display-5 text-center">助教清單</h2>
        <!-- TODO: component -->
        <new-friend @add-content="addContent"></new-friend>
        <div>
            <ul>
                <!-- 透過 v-for 傳遞每個 friend 物件作為 props -->
                <!--  NOTE 也可以使用【:】去動態綁定 -->
                <friend-contact v-for="friend in friends" :key="friend.id" :friend="friend" @update-friend="toggleUpdateFriend" @delete-friend="deleteFriend" />
            </ul>
        </div>
    </section>
</template>

<script>
export default {
    data() {
        return {
            friends: [
                { id: "001", name: "吉伊卡哇", phone: "77777777", email: "77777777@gmail.com" },
                { id: "002", name: "小八貓", phone: "88888888", email: "88888888@gmail.com" },
                { id: "003", name: "兔兔", phone: "999999999", email: "999999999@gmail.com" },
                { id: "004", name: "小桃鼠   ", phone: "66666666666", email: "66666666666@gmail.com" },
            ],
        };
    },
    methods: {
        toggleUpdateFriend(friendID) {
            // 找到對應的 friend 並更新 ID
            const identifyFriend = this.friends.find((i) => i.id === friendID);
            if (identifyFriend) {
                identifyFriend.name += "!!!";
            }
            alert("emit work!");
        },
        addContent(name, phone, email) {
            const newFriendContact = {
                id: new Date().toISOString(),
                name: name,
                phone: phone,
                email: email,
            };
            this.friends.push(newFriendContact);
        },
        deleteFriend(friendID) {
            this.friends = this.friends.filter((i) => i.id !== friendID);
        },
    },
    computed: {},
};
</script>

<style></style>
