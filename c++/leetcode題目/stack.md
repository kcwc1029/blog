## 1. stack

### 1.1. 20.Valid Parentheses

-   括弧配對的話，就想法要想清楚。
-   如果是碰到各種左括弧=>無腦 push 進去。
-   不是左括弧的話，那就是右括弧。(那要去想，甚麼樣的條件，可以 pop=>不如去想說，甚麼樣的條件是 false。)
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for(int i=0;i<n;i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else{
                if(st.empty()) return false;
                if(s[i]==')' && st.top() != '(') return false;
                if(s[i]==']' && st.top() != '[') return false;
                if(s[i]=='}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
```
### 1.2. 22.Generate Parentheses
- 可以直接從程式碼去看~
- 遞迴長相
```
          ""
         /   \
       "("   不合法 (右括號不能先出現)
      /   \
   "(("    "()"
  /   \   /   \
"(((" "(()" "()" "(())"
```
- 遞歸參數：
	- n：括弧對數
	- left：已經生成的左括號 ( 的數量。
	- right：已經生成的右括號 ) 的數量。
	- cur：當前已經生成的括號字串。
	- res：存放所有合法的括號組合。
- 結束條件：當 left == 0 且 right == 0 時，表示所有的括號都用完了，當前的 cur 是合法的，將其加入結果集。
- 非法情況：當 left > right 時，直接返回。這是因為右括號 ) 已經多於左括號 (，此時無法形成合法的組合。
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        // 開使backtracking
        backTracking(n, 0, 0, s, ans);
        return ans;
    }
    void backTracking(int n, int left, int right, string s, vector<string>& ans){
        // 非法條件
        if(left<right) return;
        // 做完條件
        if(left==n && right==n){
            ans.push_back(s);
            return;
        }
        // 繼續遞迴
        if (left < n) backTracking(n, left + 1, right, s + "(", ans);  // 添加左括號
        if (right < left) backTracking(n, left, right + 1, s + ")", ans);  // 添加右括號
    }
};
```
### 1.3. 225.Implement Stack using Queues
- 用兩個queue去實現stack
- 只有push的時候要注意，當push兩個以上時，需要去把兩個queue交換(順序顛倒)
```cpp
class MyStack {
public:
    queue<int> queue1; // 主隊列
    queue<int> queue2; // 輔助隊列
    
    MyStack() {    
    }
    
    // Push 元素到棧頂
    void push(int x) {
        queue2.push(x); // 將新元素推入 queue2
        
        // 將 queue1 的所有元素轉移到 queue2
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        // 交換 queue1 和 queue2，讓 queue1 始終保存最終結果
        swap(queue1, queue2);
    }
    
    // 從棧頂移除元素並返回
    int pop() {
        int topElement = queue1.front(); // 獲取棧頂元素
        queue1.pop(); // 刪除棧頂元素
        return topElement;
    }
    
    // 獲取棧頂元素
    int top() {
        return queue1.front(); // 棧頂即為 queue1 的隊首
    }
    
    // 判斷棧是否為空
    bool empty() {
        return queue1.empty();
    }
};
```
### 1.4. 232.Implement Queue using Stacks
- 用兩個stack去實現queue
- 要注意的是，因為stack順序改成queue只能一次，所以push時就先不要動，在pop跟peek時候，再用檢查的方式，決定要不要做顛倒
![upgit_20250121_1737456465.png|800px](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250121_1737456465.png)

```cpp
class MyQueue {
public:
    stack<int> stack1; // 主棧，存放新插入的元素
    stack<int> stack2; // 輔助棧，反轉順序以實現 FIFO
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x); // 直接壓入 stack1 
    }
    
    int pop() {
        if(stack2.empty()){
            // stack1吐給stack2
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // 如果stack2還有東西，那就直接丟出去
        int ans = stack2.top();
        stack2.pop();
        return ans;
    }
    
    int peek() {
        if(stack2.empty()){
            // stack1吐給stack2
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // 如果stack2還有東西，那就直接丟出去
        int ans = stack2.top();
        return ans;
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};
```
