#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {
   return 0;
}


class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
    int n = nums.size();
    vector<int> cnt(2,0);
    for(int i = n - 1;i >= 0;i--)
    {
        int x = nums[i] % 2;
        nums[i] = cnt[(x + 1) % 2];
        cnt[x]++;
    }
    return nums;
    }
};