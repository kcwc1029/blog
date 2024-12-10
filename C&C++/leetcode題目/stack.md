## stack

### 20.Valid Parentheses

-   括弧配對的話，就想法要想清楚。
-   如果是碰到各種左括弧=>無腦 push 進去。
-   不是左括弧的話，那就是右括弧。
    -   那要去想，甚麼樣的條件，可以 pop=>不如去想說，甚麼樣的條件是 false。

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
