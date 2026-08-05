#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        long long sum = 0;
        if(k == 0)
            return nums;
        if(n < 2*k + 1)
            return ans;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            if(i < 2*k)
                continue;
            ans[i - k] = sum / (2*k + 1);
            sum -= nums[i - 2*k];
        }
        return ans;
    }
};