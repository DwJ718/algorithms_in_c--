#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool can(vector<int>& nums,int maxOperations,int mid)
    {
        int times = 0;
        for(auto x:nums)
        {
            if(x > mid)
            {
                times += (x+mid-1)/mid - 1;//本来就有了一个袋子
                if(times > maxOperations)
                    return false;
            }
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 0;
        int r = *max_element(nums.begin(),nums.end());
        while(l + 1 < r)
        {
            int mid = l + (r - l)/2;
            if(can(nums,maxOperations,mid))
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};