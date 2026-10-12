#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long sum = 0,pre = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(2 * (i + 1) == nums.size())
                pre = sum;
        }
        int ans = 0;
        if(pre > sum - pre)
            ans++;
        for(int i = 0 ; i < nums.size() - 1; i++)
        {
            pre = pre - nums[i] + nums[(i + nums.size() / 2) % nums.size()];
            if(pre > sum - pre)
                ans++;
        }
        return ans;
    }
};


/*
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size(), half = n / 2;
        long long sum = 0, pre = 0;
        for (int x : nums) sum += x;
        for (int i = 0; i < half; i++) pre += nums[i];

        int ans = 0;
        for (int k = 0; k < n; k++) {
            if (pre > sum - pre) ans++;
            // 滑动到下一个起点 k+1
            pre = pre - nums[k] + nums[(k + half) % n];
        }
        return ans;
    }
};
*/