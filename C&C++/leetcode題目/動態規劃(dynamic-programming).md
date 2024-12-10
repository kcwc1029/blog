### 70.Climbing Stairs

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

``
