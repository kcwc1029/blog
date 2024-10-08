初等題目 (Easy)
Two Sum - #1
- 暴力解
```cpp
// 它是要返回索引
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){ // i, j 不要有相同情況
                if(nums[i]+nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};
```
Best Time to Buy and Sell Stock - #121
Maximum Subarray - #53
Move Zeroes - #283
Remove Duplicates from Sorted Array - #26
Find Pivot Index - #724
Contains Duplicate - #217
Valid Mountain Array - #941
Squares of a Sorted Array - #977
Replace Elements with Greatest Element on Right Side - #1299
Third Maximum Number - #414
Find All Numbers Disappeared in an Array - #448
Majority Element - #169
Find the Index of the First Occurrence in a String - #28
Merge Sorted Array - #88
Intersection of Two Arrays II - #350
Plus One - #66
Remove Element - #27
Missing Number - #268
Merge Two Sorted Lists - #21
Max Consecutive Ones - #485
Check If N and Its Double Exist - #1346
Sum of All Odd Length Subarrays - #1588
Remove Duplicates from Sorted List - #83
Sort Array by Parity - #905
Height Checker - #1051
Valid Anagram - #242
Merge Intervals - #56
中等題目 (Medium)
Subarray Sum Equals K - #560
Product of Array Except Self - #238
Rotate Array - #189
Find Minimum in Rotated Sorted Array - #153
Longest Consecutive Sequence - #128
Next Permutation - #31
3Sum - #15
Container With Most Water - #11
Game of Life - #289
Spiral Matrix - #54
Search in Rotated Sorted Array - #33
Minimum Size Subarray Sum - #209



