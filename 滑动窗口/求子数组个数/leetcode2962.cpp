#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // 1. 找到数组中的最大值
        // 用标准库的 max_element，返回迭代器，解引用得到最大值
        int mx = *max_element(nums.begin(), nums.end());
        
        long long ans = 0;      // 答案，统计满足条件的子数组个数
        int cnt_mx = 0;         // 当前窗口 [left, right] 内最大值 mx 的出现次数
        int left = 0;           // 窗口左边界
        
        // 2. 遍历数组，枚举每个元素作为窗口的右边界
        for (int x : nums) {
            // 将当前元素 x 加入窗口（作为新的右边界）
            // 如果 x 等于最大值 mx，则最大值出现次数 +1
            if (x == mx) {
                cnt_mx++;
            }
            
            // 3. 当窗口内最大值 mx 的出现次数达到 k 次时
            // 说明当前窗口 [left, right] 已经满足条件
            // 尝试移动左指针，找到所有以 right 为右端点的满足条件的子数组
            while (cnt_mx == k) {
                // 如果左边界元素是最大值，移出后最大值计数 -1
                if (nums[left] == mx) {
                    cnt_mx--;
                }
                // 左指针右移，窗口缩小
                left++;
            }
            
            // 4. 此时 while 循环结束，说明窗口 [left, right] 内
            //    最大值 mx 的出现次数 < k，不满足条件
            
            // 但是！在 while 循环中，left 每向右移动一次，
            // 就代表找到了一个以 right 为右端点的满足条件的子数组
            
            // 所有以 right 为右端点、左端点在 [0, left-1] 范围内的子数组都满足条件
            // 数量恰好等于 left（左端点可以是 0, 1, 2, ..., left-1）
            ans += left;
        }
        
        return ans;
    }
};