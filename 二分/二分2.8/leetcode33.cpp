#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int last = nums.back();
        int left = -1, right = nums.size() - 1; // 开区间 (-1, n-1)
        while (left + 1 < right) { // 开区间不为空
            int mid = left + (right - left) / 2;
            int x = nums[mid];
            if (target > last && x <= last) { // target 在第一段，x 在第二段
                right = mid; // 下轮循环去左边找
            } else if (x > last && target <= last) { // x 在第一段，target 在第二段
                left = mid; // 下轮循环去右边找
            } else if (x >= target) { // 否则，x 和 target 在同一段，这就和方法一的 lower_bound 一样了
                right = mid;
            } else {
                left = mid;
            }
        }
        return nums[right] == target ? right : -1;
    }
};