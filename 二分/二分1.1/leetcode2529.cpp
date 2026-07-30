#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
    int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
    int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
    return max(neg, pos);
    }
};
int main() {
   return 0;
}
//lower_bound()返回第一个大于等于x的，upper_bound()返回第一个大于x的，两者共同点就是都没有时返回nums.end()