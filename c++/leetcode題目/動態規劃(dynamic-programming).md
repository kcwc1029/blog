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

### 1.2. 62.Unique Paths
- 法1：排列組合數學計算
![upgit_20250107_1736228230.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/01/upgit_20250107_1736228230.png)

```cpp
class Solution {
public:
    // 使用迴圈實現階層
    long long factorial(int n) {
        long long result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
    int uniquePaths(int m, int n) {
        return factorial(m+n-2) / (factorial(m-1) * factorial(n-1));
    }
};
```

- 但上述的解法會抱錯，在於factorial(m+n-2)太大了，因此要優化
```cpp
// 進一步優化
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        // 選擇較小的 b，計算 C(m+n-2, b)
        int b = min(m - 1, n - 1);
        for (int i = 1; i <= b; ++i) {
            result = result * (m + n - 1 - i) / i; 
        }
        return result;
    }
};
```
- 解法2：DP
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            v[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            v[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                v[i][j] = v[i - 1][j] + v[i][j - 1]; // 當前 = 上面+左邊
            }
        }
        return v[m - 1][n - 1];
    }
};
```
- 針對解法2：二維DP壓縮成一為DP
![Image](https://media.discordapp.net/attachments/1286741860538122281/1326360050201006171/image.jpg?ex=677f248e&is=677dd30e&hm=c9caebc178a1839d0393b7f887b380909e6c92020a880c468ed955ffd3beac63&=&format=webp&width=810&height=229)

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1); // 設為1表示第一行(全部像右)
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
```
### 1.3. 63.Unique Paths II
- 她是基於62，但中間多了障礙物
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // 要先全部塞0
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1) break;
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==1) break;
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```

- 針對解法1：二維DP壓縮成一為DP
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> dp(n, 0); // 初始化一維DP陣列
        dp[0]=1; // 預設在第一行的第一步有走出去

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // 如果遇到障礙物，設為0
                } else if (j > 0) {
                    dp[j] = dp[j] + dp[j - 1]; // 計算當前格子的路徑數
                }
            }
        }
        return dp[n-1];
    }
};
```

### 1.4. 64.Minimum Path Sum
- 他一樣是要從左上到右下
- 解法：dp
```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        
        // NOTE: 處裡左邊第一col
        for(int i=1;i<m;i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        // NOTE: 處裡第一row
        for(int i=1;i<n;i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        // 其他部分，就一直dp下去
        // 上格根左格看哪一個步數比較少，當前格去加比較少格的
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int temp = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = grid[i][j] + temp;
            }
        }
        return dp[m-1][n-1];
    }
};
```
