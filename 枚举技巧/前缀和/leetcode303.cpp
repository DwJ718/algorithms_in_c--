#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class NumArray {
    vector<int> s;
public:
    NumArray(vector<int>& nums) {
        s.resize(nums.size() + 1);
        for(int i = 0 ; i < nums.size(); i++)
        {
            s[i + 1] = s[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */