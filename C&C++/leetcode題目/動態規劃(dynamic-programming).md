### 0.1. 70.Climbing Stairs

-   給階層數，一次只能走 1 或 2 步，求該階層有幾種走法。
    ![upgit_20241129_1732864640.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241129_1732864640.png)

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n+1;i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```


## 1. medium
### 1.1. 53.Maximum Subarray
- 找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
- 解法1：前缀和
![upgit_20250101_1735711113.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250101_1735711113.png)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int min_pre_sum = 0;
        int pre_sum = 0;

        for(int i=0;i<nums.size();i++){
            pre_sum+=nums[i];
            ans = max(ans, pre_sum-min_pre_sum);
            min_pre_sum = min(min_pre_sum, pre_sum);
        }
        return ans;
    }
};
```

- 解法2：DP
![upgit_20250101_1735712121.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250101_1735712121.png)
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = max(dp[i-1], 0) + nums[i];
        }
        return *max_element(dp.begin(), dp.end()); // 從陣列中找到最大值
    }
};
```









