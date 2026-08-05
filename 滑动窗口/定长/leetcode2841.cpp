#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> mp;
        long long ans = 0;
        long long sum = 0;
        long long max_s = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            sum += nums[i];
            if(i < k - 1)
                continue;
            if(mp.size() >= m)
                max_s = max(max_s,sum);
            sum -= nums[i - k + 1];
            if(--mp[nums[i - k + 1]] == 0)
                mp.erase(nums[i - k + 1]);
        }
        return max_s;
    }
};