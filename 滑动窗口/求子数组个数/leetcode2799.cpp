#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // 第一步：计算整个数组中有多少种不同的元素
        // 用 unordered_set 去重，得到不同元素的个数 k
        unordered_set<int> st(nums.begin(), nums.end());
        int k = st.size();  // k = 整个数组的不同元素总数
        
        // cnt 用于统计当前滑动窗口内每种元素出现的次数
        unordered_map<int, int> cnt;
        
        int ans = 0;    // 答案：完全子数组的个数
        int left = 0;   // 滑动窗口的左边界
        
        // 枚举右边界 right，遍历 nums 中的每个元素 x
        for (int x : nums) {
            // 1. 将当前元素 x 加入窗口（作为新的右边界）
            cnt[x]++;
            
            // 2. 当窗口内不同元素的种类数 == k 时，说明窗口已经"完全"
            //    此时窗口 [left, right] 是一个完全子数组
            //    同时，左边界 left 继续右移，可以找到更多以 right 结尾的完全子数组
            while (cnt.size() == k) {
                // 记录要移出窗口的元素（当前左边界指向的元素）
                int out = nums[left];
                
                // 将该元素从窗口中移除
                // --cnt[out] 先减1，如果减到 0，说明这个种类在窗口中消失
                if (--cnt[out] == 0) {
                    // 从哈希表中删除这个键，这样 cnt.size() 就会减少
                    cnt.erase(out);
                }
                
                // 左边界右移，窗口缩小
                left++;
            }
            
            // 3. 此时 while 循环结束，说明窗口 [left, right] 不再完全
            //    即窗口内不同元素种类数 < k
            //    但是！在 while 循环中，left 每向右移动一次，
            //    就代表找到了一个以 right 为右端点的完全子数组
            //    所以 left 移动了多少次，就找到了多少个完全子数组
            
            // 关键理解：当 left 从 0 移动到当前值时，
            // 所有以 right 为右端点、左端点在 [0, left-1] 范围内的子数组都是完全子数组
            // 数量恰好等于 left（因为左端点可以是 0, 1, 2, ..., left-1）
            ans += left;
        }
        
        return ans;
    }
};