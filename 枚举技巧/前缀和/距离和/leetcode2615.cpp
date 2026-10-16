#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        // 记录每个值出现的所有下标
        unordered_map<int, vector<int>> posMap;
        for (int i = 0; i < n; ++i) {
            posMap[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n, 0);
        
        // 对每个值单独处理
        for (auto& [val, pos] : posMap) {
            int k = pos.size();
            // 构造前缀和：prefix[t] = pos[0] + ... + pos[t-1]
            vector<long long> prefix(k + 1, 0);
            for (int t = 0; t < k; ++t) {
                prefix[t + 1] = prefix[t] + pos[t];
            }
            long long total = prefix[k];  // 所有下标之和
            
            for (int t = 0; t < k; ++t) {
                long long leftSum = prefix[t];              // pos[0..t-1] 的和
                long long rightSum = total - prefix[t + 1]; // pos[t+1..k-1] 的和
                
                long long leftPart  = (long long)t * pos[t] - leftSum;
                long long rightPart = rightSum - (long long)(k - 1 - t) * pos[t];
                
                ans[pos[t]] = leftPart + rightPart;
            }
        }
        
        return ans;
    }
};