#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int max_l = 0;

        for(int r = 0 ; r < n; r++)
        {
            if(nums[r] == 0)
                k--;
            while(k < 0)
            {
                if(nums[l] == 0)
                    k++;
                l++;
            }
            max_l = max(r - l + 1,max_l);
        }
        return max_l;
    }
};