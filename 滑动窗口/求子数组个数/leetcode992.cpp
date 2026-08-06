#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
    // 统计不同整数个数 <= k 的子数组数量
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        int distinct = 0;
        int left = 0;
        int ans = 0;
        
        for (int right = 0; right < n; right++) {
            int x = nums[right];
            cnt[x]++;
            if (cnt[x] == 1) distinct++;
            
            while (distinct > k) {
                int out = nums[left];
                cnt[out]--;
                if (cnt[out] == 0) distinct--;
                left++;
            }
            
            // 以 right 为右端点，左端点从 left 到 right 都满足
            ans += right - left + 1;
        }
        
        return ans;
    }
};