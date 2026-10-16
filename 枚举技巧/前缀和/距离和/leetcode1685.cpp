#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        //有绝对值考虑如何去掉绝对值
        int n = nums.size();
        long long totalSum = 0;
        for (int x : nums) totalSum += x;
        
        vector<int> result(n);
        long long prefixSum = 0;  // nums[0..i-1] 的和
        
        for (int i = 0; i < n; ++i) {
            long long leftSum = prefixSum;                        // sum of nums[0..i-1]
            long long rightSum = totalSum - prefixSum - nums[i];  // sum of nums[i+1..n-1]
            
            long long leftPart  = (long long)i * nums[i] - leftSum;
            long long rightPart = rightSum - (long long)(n - i - 1) * nums[i];
            
            result[i] = (int)(leftPart + rightPart);
            
            prefixSum += nums[i];
        }
        
        return result;
    }
};
