### 0.1. 2.Add Two Numbers
- 節點上面做加總
![upgit_20241204_1733301476.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241204_1733301476.png)

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // 最後返回
        ListNode* node = dummy; // 紀錄加總後的節點
        int carry = 0; // 紀錄進位
        while(l1 || l2 || carry){
            // 處裡已經跑完的節點    
            int l1_val = (l1 != nullptr) ? l1->val : 0; // 如果 l1 不為空，取其值；否則取 0
            int l2_val = (l2 != nullptr) ? l2->val : 0; // 如果 l2 不為空，取其值；否則取 0

            int sum = l1_val + l2_val + carry; // 將 l1、l2 的值以及 carrier 相加

            // 處裡加總後的節點
            node->next = new ListNode(sum%10);
            node = node->next;
            carry = sum/10;

            // l1 l2前進
            if(l1!=nullptr) l1 = l1->next;
            if(l2!=nullptr) l2 = l2->next;
        }
        return dummy->next;
    }
};
```

### 0.2. 21.Merge Two Sorted Lists
![upgit_20241210_1733813202.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241210_1733813202.png)
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0); // 最後返回
        ListNode* curr = dummy; // 紀錄加總後的節點
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val < list2->val){
                // 把她接在curr(回傳值)的下一個
                curr->next = list1;
                // 更新當前
                curr = curr->next;
                list1 = list1->next;
            }else{
                // 把她接在curr(回傳值)的下一個
                curr->next = list2;
                // 更新當前
                curr = curr->next;
                list2 = list2->next;
            }
        }
        // 離開迴圈->剩一邊有資料
        if(list1!=nullptr)curr->next = list1;
        else curr->next = list2;

        return dummy->next;
    }
};
```
### 0.3. 24.Swap Nodes in Pairs
- 解法1：遞迴
![upgit_20241210_1733814466.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241210_1733814466.png)
```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 終止條件
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* p1 = head->next;
        ListNode* p2 = head->next;

        // recusion
        p1->next = swapPairs(p2->next);
        p2->next = p1;

        return p2;
    }
};
```








