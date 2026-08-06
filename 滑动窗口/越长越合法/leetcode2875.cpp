#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long sum = 0;
        for (int x : nums) sum += x;
        
        // 计算完整周期数
        long long full = target / sum;
        int rest = target % sum;
        
        // 如果 rest == 0，可以直接返回 full * n
        // 但还要检查是否有更短的子数组（比如部分和等于 sum）
        // 所以让 rest = sum，full--，统一处理
        int ans = INT_MAX;
        
        // 情况1：部分和等于 rest（rest > 0）
        if (rest > 0) {
            int len = findMinSubarray(nums, rest);
            if (len != -1) {
                ans = min(ans, (int)(full * n + len));
            }
        }
        
        // 情况2：部分和等于 sum + rest（相当于多包含一个完整周期）
        // 如果 rest == 0，部分和等于 sum 也是一种情况
        int len2 = findMinSubarray(nums, rest + sum);
        if (len2 != -1) {
            // 因为多包含了一个完整周期，所以完整周期数要减1
            ans = min(ans, (int)((full - 1) * n + len2));
        }
        
        // 特殊情况：如果 rest == 0，部分和等于 sum 的情况已经包含
        // 但可能直接 full * n 就是答案
        if (rest == 0) {
            ans = min(ans, (int)(full * n));
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
    
    // 在无限循环数组中，找和等于 target 的最短子数组长度
    // 注意：这里 target 可能很大，但保证能找到的和不超过 2*sum
    int findMinSubarray(vector<int>& nums, long long target) {
        int n = nums.size();
        // 复制成两倍
        vector<int> nums2(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            nums2[i] = nums[i % n];
        }
        
        // 前缀和
        vector<long long> prefix(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + nums2[i];
        }
        
        // 滑动窗口找和等于 target 的最短子数组
        int l = 0;
        long long windowSum = 0;
        int minLen = INT_MAX;
        
        for (int r = 0; r < 2 * n; r++) {
            windowSum += nums2[r];
            
            while (windowSum > target && l <= r) {
                windowSum -= nums2[l];
                l++;
            }
            
            if (windowSum == target) {
                minLen = min(minLen, r - l + 1);
            }
        }
        
        return minLen == INT_MAX ? -1 : minLen;
    }
};