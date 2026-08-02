#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // 如果 mid 是奇数，减1变成偶数
            if (mid % 2 == 1) {
                mid--;
            }
            
            // 现在 mid 是偶数，检查是否和下一个配对
            if (nums[mid] == nums[mid + 1]) {
                // 配对成功，单独元素在右边
                left = mid + 2;
            } else {
                // 配对失败，单独元素在左边（或就是 mid）
                right = mid;
            }
        }
        
        return nums[left];
    }
};