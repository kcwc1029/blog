### 0.1. 模板
```cpp
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```
### 0.2. 17.Letter Combinations of a Phone Number

![upgit_20241207_1733561921.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241207_1733561921.png)

```cpp
class Solution {
public:
    map<char, string> phoneMap{
        {0, ""},
        {1, ""},
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    void backtracking(vector<string>& ans,
                    string& s,
                    const string& digits,
                    int index){
        // 終止條件：若index等於digits長度，表示已選好全部字母
        if(index==digits.size()){
            ans.push_back(s);
            return ;
        }

        int digit=digits[index]-'0';
        string letter=phoneMap[digit];
        for(int i=0;i<letter.size();i++){
            s.push_back(letter[i]);
            backtracking(ans, s, digits, index+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        // NOTE: 重組各種s，然後裝晉ans
        vector<string> ans;
        string s;
        // NOTE: 極端條件
        if(digits=="") return ans;
        backtracking(ans, s, digits, 0);

        return ans;
    }
};
```
### 0.3. 78.Subsets
```cpp
class Solution {
public:
    void backtracking(vector<vector<int>>& ans,vector<int>& temp,vector<int>& nums,int x){
        // 依照要求，本題要先放，再做檢查
        ans.push_back(temp);
        // 終止條件
        if(x==nums.size()) return;

        for(int i=x;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtracking(ans, temp, nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtracking(ans, temp, nums, 0);
        return ans;
    }
};
```

### 0.4. 39.Combination Sum
- 返回各種組合(元素可重複)
![upgit_20241220_1734664775.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734664775.png)

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    void backtracking(vector<int>& candidates, vector<int>& path, int target, int sum, int startIndex){
        // 終止條件
        if(sum>target) return;
        if(sum==target){
            ans.push_back(path);
            return;
        }
        for(int i=startIndex;i<candidates.size();i++){
            sum+=candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, path, target, sum, i);
            sum-=candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        // backtracking(candidates, path, target, sum, startIndex)
        backtracking(candidates, path, target, 0, 0);
        return ans;
    }
};
```


### 0.5. 40.Combination Sum II
- 根據39題，但不能重複
```cpp
class Solution {
public:
    vector<vector<int>> ans;
    void backtracking(vector<int>& candidates, vector<int>& path, int target, int startIndex){
        // 終止條件
        if(target<0) return;
        if(target==0){
            ans.push_back(path);
            return;
        }

        for(int i=startIndex;i<candidates.size();i++){
            // 去重邏輯：同一層中出現重複數字時跳過
            // 比較：【當前數字】是否在【之前】出現過
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            backtracking(candidates, path, target - candidates[i], i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        // backtracking(candidates, path, target, startIndex);
        backtracking(candidates, path, target, 0);
        return ans;
    }
};
```