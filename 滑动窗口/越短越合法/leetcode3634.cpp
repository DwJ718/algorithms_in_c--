#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int max_l = 0;
        for(int r = 0;r < n;r++)
        {
            while(1LL *nums[l] * k < 1LL *nums[r])
            {
                l++;
            }
            max_l = max(r - l + 1,max_l);
        }
        return n - max_l;
    }
};