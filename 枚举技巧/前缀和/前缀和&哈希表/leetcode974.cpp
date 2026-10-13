#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> cnt;
        //cnt[0] = 1;                    // 前缀和为 0 出现一次
        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum = ((sum + nums[i]) % k + k) % k;   // 保证非负
            ans += cnt[sum];           // 之前出现过相同余数，就能组成若干子数组
            cnt[sum]++;
        }
        return ans + cnt[0];
    }
};