## 雙指針(two-pointers)
### 26. Remove Duplicates from Sorted Array
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