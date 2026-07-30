#include<bits/stdc++.h>//万能头文件
using namespace std;
class Solution {
    int lower_bound(vector<int>& nums, int target)
    {
        int l = -1;
        int r = nums.size();
        int mid;
        while(l + 1 < r)
        {
            mid = l + (r - l)/2;
            if(nums[mid] < target)
                l = mid;
            else
                r = mid;
        }
        return r;
    }
public:
    int search(vector<int>& nums, int target) 
    {
        int ans = lower_bound(nums,target);
        return ans < nums.size() && nums[ans] == target ? ans : -1;
    }
};
int main() {

}