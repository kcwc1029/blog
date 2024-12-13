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
