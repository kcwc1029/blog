## 模擬
### 66. Plus One
- ![upgit_20241106_1730892149.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730892149.png)
```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1;i>-1;i--){
            if(digits[i]!=9){ // 情況1
                digits[i]+=1;
                return digits;
            }else{ // 情況2
                digits[i] = 0;
            }
        }
        // 情況3
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};
```

### 88. Merge Sorted Array
- 解法1：額外開一個空間，兩兩比較，然後再把值丟到新的arr。
![upgit_20241106_1730893985.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730893985.png)

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=0, p2=0; // 宣告指針
        int ans[m+n]; // 宣告新陣列
        int cur; // 佔存目前最小的值

        // 重複比較 -> 條件：還有值
        // 這邊我用OR，表示兩個arr間，只要有其中一個還有數值，就會繼續運行
        while (p1<m || p2<n){ 
            // 可能條件：
            // nums1[p1]<nums2[p2] => 把nums1[p1]排到新arr
            // nums1[p1]>=nums2[p2] => 把nums2[p2]排到新arr ->這個條件我放最後else寫
            // nums1跑完了 => => 把nums2[p2]排到新arr (檢查邊界要先寫，不然最後會超出邊界爆錯)
            // nums2跑完了 => => 把nums1[p1]排到新arr (檢查邊界要先寫，不然最後會超出邊界爆錯)
            if(p2 == n){
                cur = nums1[p1];
                p1++;
            }else if(p1 == m){
                cur = nums2[p2];
                p2++;
            }else if(nums1[p1]<nums2[p2]){
                cur = nums1[p1];
                p1++;
            }else{
                cur = nums2[p2];
                p2++;
            }
            // 統一放
            ans[p1+p2-1] = cur;
        }

        // 最後再倒回去
        for(int i=0;i<m+n;i++){
            nums1[i] = ans[i];
        }
    }
};
```
- 解法2：進行優化。在num1排就好啦~
![upgit_20241106_1730894582.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730894582.png)

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1, p2=n-1; // 宣告指針   
        int tail =(m+n)-1; // 尾巴的那根指針
        int cur; // 佔存目前最大的值
        // 跑到甚麼時候?
        while(p1>-1 ||p2>-1){
            // 檢查邊界
            if(p1==-1){
                cur  = nums2[p2];
                p2--;
            }else if (p2 == -1) {
                cur  = nums1[p1];
                p1--;
            }else if(nums1[p1] > nums2[p2]){
                cur  = nums1[p1];
                p1--;
            }else{
                cur  = nums2[p2];
                p2--;
            }
            nums1[tail] = cur;
            tail--;
        }
    }
};
```

## 二維陣列
### 118. Pascal’s Triangle
- 題目是返回整個三角型。
```
​[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]​
step1：每一row的第0位跟第n位放1 => 更快點，直接全部塞1
step2：arr[i][i] = arr[i][i-1] + arr[i-1][i-1]
```
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows); // 宣告二維陣列
        for (int i = 0; i < numRows; i++){
            ans[i].resize(i + 1);
            ans[i][0]=1;
            ans[i][i]=1;
            for(int j=1;j<i;j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};
```

### 118. Pascal’s Triangle II
- 這一題她是只要返回某一層
- 那我這一題是沒有優化，按照前一題，多做一層並返回他指定的。
```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1); // 宣告二維陣列
        for (int i = 0; i < rowIndex+1; i++){
            ans[i].resize(i + 1);
            ans[i][0]=1;
            ans[i][i]=1;
            for(int j=1;j<i;j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans[rowIndex];
    }
};
```


## 雙指針(two-pointers)
### 26. Remove Duplicates from Sorted Array
- 這題可以當考題
![upgit_20241105_1730803543.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241105_1730803543.png)

```cpp
class Solution {
public:
    // 解法1
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left=0; // 左指針
        for(int right=0;right<n;right++){ // 右指針
            if(nums[right]!=nums[left]){
                left++; // 這邊要先往下，移到未處裡的位子，在把右指針的值給左指針
                nums[left] = nums[right];
                
            }
        }
        // 最後要返回的是結果長度
        return left+1;
    }
};
```
- 延伸26，26的題目是【去重複】，也可以理解為【保留1位】
- 那如果今天是【保留k位】呢
- 保留k位=>代表【前k個數值】可以保留
- 對於後面的比較：跟左指針(第k位)進行比較，不同則保留(左指針給右指針)
- ![upgit_20241105_1730805429.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241105_1730805429.png)

```cpp
class Solution {
public:
    // 解法2
    int removeDuplicates(vector<int>& nums) {
       return process(nums, 1); // 保留1位
    }

    int process(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0;
        for(int right=0;right<n;right++){
            if(left<k || nums[left-k]!=nums[right]){
                nums[left]=nums[right];
                left++;
            }
        }
        return left;
    }
};
```
### 80. Remove Duplicates from Sorted Array II

```cpp
class Solution {
public:
    // 解法：利用26題的解法2    
    int removeDuplicates(vector<int>& nums) {
        return process(nums, 2); // 保留1位
    }

    int process(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0;
        for(int right=0;right<n;right++){
            if(left<k || nums[left-k]!=nums[right]){
                nums[left]=nums[right];
                left++;
            }
        }
        return left;
    }
};
```
### 27. Remove Element
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        for(int right=0;right<n;right++){
            if(nums[right]!=val){
                // 先處理好，再往下走
                nums[left]=nums[right];
                left++;
            }
        }
        return left;
    }
};
```



## map

### 1. Two Sum
```cpp
class Solution {
public:
    // 解法1：(42 ms)
    // 因為她就是要回傳兩個嘛，所以可以先用for迴圈去定第一個，然後再用另一個for迴圈去找第二個
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // nums[i], nums[j]
                // nums[i]+nums[j]==target???
                if(nums[i]+nums[j]==target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};
```
```cpp
class Solution {
public:
    // 解法2：處理時間複雜度的問題 -> 利用map (2 ms)
    vector<int> twoSum(vector<int>& nums, int target){
        int n = nums.size();
        map<int, int> m;
        for(int i=0;i<n;i++){
            // 查找元素
            auto it = m.find(target - nums[i]);
            if(it!=m.end()){
                return {it->second, i};
            }else{
                m[nums[i]] = i; 
            }
        }
        return {};
    }
};
```

### 169. Majority Element
-  題目要找出最多的那個數值
- 解法1：用map紀錄次數，返回最多的那個
```cpp
// TODO: 解法1：用一個map紀錄，並且在遍歷map找出最多的
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        for(int i:nums){
            m[i]++;
        }
        // 遍厲map ->  key-value 配對
        for(auto& p : m) {
            if(p.second > n / 2) {   // 如果該元素出現次數超過 n/2
                return p.first;      // 返回該元素 (majority element)
            }
        }
        return 0;
    }
};
```
```cpp
// TODO: 針對map進一步優化，在記錄map的時後，一併紀錄最多的次數
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        int mostCount=0, mostNum=0;
        for(int i:nums){
            m[i]++;
            // 更新紀錄
            if(m[i]>mostCount){
                mostCount = m[i];
                mostNum = i;
            }
        }
        return mostNum;
    }
};
```
- 解法3：題目描述 【more than `⌊n / 2⌋` times】，那我只要先做排序，然後找那個在最中間的數值。
```cpp
// TODO: 用排序去解
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       return nums[nums.size() / 2];
    }
};
```
### 287. Find the Duplicate Number
- 題目是要在長度(n+1)找範圍1到n中的一個重複整數。
- 不能修改數組
- 解法1：用map
```cpp
class Solution {
public:
    // 解法1：用map紀錄
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(auto i:nums){
            if(m[i]>0){
                return i;
            }else{
                m[i]++;
            }
        }
        return -1;
    }
};
// - Your runtime beats 5.25 % of cpp submissions
// - Your memory usage beats 10.3 % of cpp submissions (89.5 MB)
```
- 好啦~要來進一步優化
- 解法2是用linked的方式
- [Floyd's Cycle Detection Algorithm (Floyd判圈算法) 龜兔賽跑算法 (youtube.com)](https://www.youtube.com/watch?v=xS5eL9qkffA)
- ![upgit_20241108_1731040041.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731040041.png)

```cpp
class Solution {
public:
    // 解法2：linked
    int findDuplicate(vector<int>& nums) {
        int fast=0, slow=0; // 快慢指針
        while(true){
            fast = nums[fast];
            fast = nums[fast];
            slow = nums[slow];
            if(slow==fast)break;
        }
        // 形成循環後，最後的終點就是重複點
        int ptr = 0;
        while(ptr!=slow){
            ptr = nums[ptr];
            slow = nums[slow];
        }
        return ptr;
    }
};
// - Your runtime beats 52.42 % of cpp submissions
// - Your memory usage beats 98.91 % of cpp submissions (63.7 MB)
```
- 解法3：二分+抽屜原理
- 抽屉原理(Pigeonhole Principle)：如果有 `n + 1` 個數字在 `1` 到 `n` 的範圍內，那麼至少有一個數字是重複的。
- ![upgit_20241108_1731041451.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241108_1731041451.png)
```cpp
class Solution {
public:
    // 解法3：二分+抽屜原理
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // NOTE:設定一開始的範圍： 1到n的範圍
        int left = 1, right=n-1;
        int ans=-1;
        while(left<=right){
            // NOTE: 抽屜原理
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid) count ++;
            }
            if(count<=mid) left = mid +1;
            else{
                right = mid - 1;
                ans = mid; // 每次去更新最後答案
            }
        }
        return ans;
    }
};
// - Your runtime beats 42.99 % of cpp submissions
// - Your memory usage beats 52.83 % of cpp submissions (63.9 MB)
```
## set
### 217. Contains Duplicate
- 他要找【是否有重複】
```cpp
class Solution {
public:
    // 解法1：用排序
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};
```
```cpp
class Solution {
public:
    // 解法2：用set
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i:nums){
            // 查詢是否存在
            if (s.find(i) != s.end()) return true;
            else s.insert(i);
        }
        return false;
    }
};
```


## 二分搜尋
### 35. Search Insert Position
- 返回他的索引位置
- 可能就兩種解法：第一種是從頭往後找過去；要優化就二分
```cpp
class Solution {
public:
    // 解法1：由頭往後
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>= target){
                return i;
            }
        }
        return n; // 最後面(最大)
    }
};
```
- 二分搜尋的模板
```cpp
step1：會有3個東西
左指針、右指針、中指通(????
中指針是由左右指針位置平均
int left = 0, right = arr.size()-1;

step2：
要一值重複去計算中指針=>while
while(left<=right){
    int mid = left + (right - left) / 2;
}

step3：中指針就會有三種情況，是情況再去處理左右指針
if(arr[mid]==target) return mid
else if(arr[mid]<target) left = mid + 1;
else (arr[mid]>target) right = mid - 1;
```

```cpp
class Solution {
public:
    // 解法2：二分搜尋
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) right = mid-1;
            else left = mid + 1;
        }
        return left; // 最後會重疊，那我取left
    }
};
```

## DP
### 121. Best Time to Buy and Sell Stock
- 解法1：用爆力解方式：定一個點(for loop)，然後另一個for去跑後面的，不斷紀錄最小值。
- 解法2：DP
![upgit_20241106_1730896937.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241106_1730896937.png)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0; // 最大獲利
        int minprice = INT_MAX;
        for(int i=0;i<n;i++){
            // 順序沒差
            maxprofit = max(maxprofit, (prices[i]-minprice));
            minprice = min(minprice, prices[i]);
            
        }
        return maxprofit;
    }
};
```


