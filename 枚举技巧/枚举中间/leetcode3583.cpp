#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
    //站中间串两边
    unordered_map<int,long long> cnt1;
    unordered_map<int,long long> cnt2;
    int n = nums.size();
    long long ans = 0;
    long long mod = 1e9 + 7;
    cnt1[nums[0]]++;
    for(int i = 2 ; i < n ; i++)
        cnt2[nums[i]]++;
    for(int i = 1 ; i < n - 1 ; i++)
    {
        ans = (ans + cnt1[nums[i] * 2] * cnt2[nums[i] * 2]) % mod;
        cnt1[nums[i]]++;
        cnt2[nums[i + 1]]--;
    }
    return ans;
    }
};


class Solution {
public:
    int specialTriplets2(vector<int>& nums) {
        const int MOD = 1000000007;
        unordered_map<int, int> cnt1;
        unordered_map<int, long long> cnt12;
        long long cnt123 = 0;
        for (int x : nums) {
            if (x % 2 == 0) {
                cnt123 += cnt12[x / 2]; // 把 x 当作 nums[k]
            }
            cnt12[x] += cnt1[x * 2]; // 把 x 当作 nums[j]
            cnt1[x]++; // 把 x 当作 nums[i]
        }
        return cnt123 % MOD;
    }
};