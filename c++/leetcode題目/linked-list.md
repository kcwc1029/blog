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
### 0.4. 83.Remove Duplicates from Sorted List
- 要刪除某格節點，就是將他的【上一個】直接指向下一個(沒人指=消失)
```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 空集合檢查
        if(head==nullptr)return head;

        ListNode* dummy = new ListNode(0); // 創建真正的 dummy 節點
        dummy->next = head;
        ListNode* curr = head;
        while(curr->next){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
```
### 0.5. 141.Linked List Cycle
- 解法：快慢指針：快指針走兩步，慢指針走一步，如果有成環，快慢指針有一天一定會相遇。
```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* left = head;
        ListNode* right = head;
        while(right && right->next){
            left = left->next;
            right = right->next->next;
            if(left==right) return true;
        }
        return false;
    }
};
```

### 0.6. 160.Intersection of Two Linked Lists
![upgit_20241212_1733970327.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241212_1733970327.png)
```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while(pA != pB){
            if(pA!=nullptr)pA = pA->next;
            else pA = headB;
            if(pB!=nullptr)pB = pB->next;
            else pB = headA;
        }
        return pA;
    }
};
```

### 0.7. 203.Remove Linked List Elements
- 刪除節點
![upgit_20241215_1734241405.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241215_1734241405.png)

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0); // 最後返回
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr->next!=nullptr){
            // 先記錄下一個點(因為要判斷，這個點484要刪除的)
            ListNode* temp = curr->next;
            if(temp->val==val){
                // 確定要珊：curr->next指向temp的下一個(跳過temp)
                curr->next = temp->next;
            }else{
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
```

### 0.8. 876.Middle of the Linked List
```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```
### 0.9. 206.Reverse Linked List
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
        這支函式用來反轉單向鏈結串列(ListNode)，方法如下:
        1. 使用三個指針: 
           - cur: 指向目前節點 
           - pre: 指向前一個節點(初始為nullptr)
           - temp: 用來暫存cur的下一個節點(避免指針失聯)
        2. 迴圈中:
           - 先用temp紀錄cur->next
           - 將cur->next指向pre，完成反轉鏈結
           - 接著pre與cur同時往前推進
        3. 迴圈結束後，pre會成為新的表頭，直接回傳pre即可
        */
        
        ListNode* cur = head;
        ListNode* pre = nullptr;
        
        while(cur != nullptr) {
            ListNode* temp = cur->next; // 暫存下一個節點
            cur->next = pre;            // 反轉指向前一個節點
            pre = cur;                  // pre往前移動
            cur = temp;                 // cur往前移動
        }
        
        return pre; // pre即為反轉後的新表頭
    }
};
```
- 使用遞迴解法
```cpp
class Solution {
public:
    // 利用遞迴反轉鏈結串列的輔助函式
    ListNode* f(ListNode* cur, ListNode* pre) {
        // 遞迴終止條件：目前節點為空時，前一個節點就是新的表頭
        if(cur == nullptr) return pre;
        // 先遞迴到底，取得反轉後的「新表頭」
        ListNode* temp = f(cur->next, cur);
        // 反轉指針：讓目前節點指向前一個節點
        cur->next = pre;
        // 回傳新表頭給上一層
        return temp;
    }

    ListNode* reverseList(ListNode* head) {
        return f(head, nullptr);
    }
};
```

### 0.10. 234.Palindrome Linked List
- 用到
	- 876檢查中間
	- 206反轉
```cpp
class Solution {
public:
    // TODO: 找到中間node
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head, *fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // TODO: 反轉linked
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr, *cur = head;
        while(cur){
            ListNode* nxt = cur->next;
            cur->next = pre;
            // 往下一個陀洞
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    // TODO: 反轉linked
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head); // 找中間
        ListNode* head2 = reverseList(mid);// 反轉
        while(head2){
            if(head->val!=head2->val){
                return false;        
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};
```

### 0.11. 86.Partition List
- 所有小于 `x` 的节点都出现在 大于或等于 `x` 的节点之前。
```
head = [1,4,3,2,5,2], x = 3
所以3後面的兩個2，要移到3前面
4跟5不用動
```
- 建立兩個指標small_dummy跟big_dummy，去把原資料拆開。
```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // 建立兩個空節點跟各自指針
        ListNode *smallDummy = new ListNode(0);
        ListNode *bigDummy = new ListNode(0);
        ListNode *small = smallDummy;
        ListNode *big = bigDummy;
        // 開始跑原本迴圈
        while(head != nullptr){
            if(head->val<x){
                small->next = head;
                small = small->next;
            }else{
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }
        // 區分成兩條後
        // 小的尾吧->大的頭
        small->next = bigDummy->next;
        // 大的尾吧皆nullptr
        big->next = nullptr;
        return smallDummy->next;
    }
};
```




### 0.12. 234.Palindrome Linked List
- 檢查Linked List484由回文組成
- 先找到中間的那個節點 => 快慢指針



