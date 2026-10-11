#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        //max -> maxdif
        int s = 0, mx = 0, mn = 0;
        for(int x : nums)
        {
            s += x;
            mx = max(mx, s);
            mn = min(mn, s);
        }
        return mx - mn;
    }
};

/*
max:
int maxSubArray(vector<int>& nums) {
    int cur = 0, ans = INT_MIN;
    for (int x : nums) {
        cur = max(x, cur + x);
        ans = max(ans, cur);
    }
    return ans;
}

min:
int minSubArray(vector<int>& nums) {
    int cur = 0, ans = INT_MAX;
    for (int x : nums) {
        cur = min(x, cur + x);  
        ans = min(ans, cur);     
    }
    return ans;
}
以某个位置结尾
*/