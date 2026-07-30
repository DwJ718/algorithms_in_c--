#include<bits/stdc++.h>//万能头文件
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        //可以转换成求大于等于target和target+1的问题，使用左开右开
        int len = nums.size();
        int l = -1;
        int r = len;
        int mid;
        while(l+1 < r)
        {
            mid = l + (r - l)/2;
            if(nums[mid] < target)
                l = mid;
            else
                r = mid;
        }
        int ans1 = r;
        if (ans1 == len || nums[ans1] != target)
            return {-1,-1};
        l=-1;
        r=len;
        while(l + 1 < r)
        {
            mid = l + (r-l)/2;
            if(nums[mid]<target+1)
                l=mid;
            else
                r=mid;
        }
        int ans2 = r-1;
        return {ans1,ans2};
    }
};
int main() {

}