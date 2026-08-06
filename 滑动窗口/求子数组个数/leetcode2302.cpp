#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;      // 答案，记录满足条件的子数组个数
        long long sum = 0;      // 当前窗口 [left, right] 的元素和
        int left = 0;           // 窗口左边界
        
        // 枚举窗口右边界
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right]; // 将 nums[right] 加入窗口
            
            // 如果当前窗口的分数 >= k，则需要收缩左边界
            // 直到窗口分数 < k 或窗口为空
            while (left <= right && sum * (right - left + 1) >= k) {
                sum -= nums[left];  // 移除左边界元素
                left++;             // 左边界右移
            }
            
            // 此时 [left, right] 是以 right 为右端点、分数 < k 的
            // 最长合法窗口。由于 nums 都是正数，窗口缩短只会让分数更小，
            // 所以以 right 为右端点的所有合法子数组有 (right - left + 1) 个：
            // [left, right], [left+1, right], ..., [right, right]
            ans += right - left + 1;
        }
        
        return ans;
    }
};