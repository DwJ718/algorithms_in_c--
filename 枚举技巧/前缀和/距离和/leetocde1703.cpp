#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        // 提取所有 1 的下标
        vector<long long> pos;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == 1) pos.push_back(i);
        }
        int m = pos.size();
        if (m < k) return 0;  
        
        // 前缀和：pre[j] = pos[0] + ... + pos[j-1]
        vector<long long> pre(m + 1, 0);
        for (int j = 0; j < m; ++j) {
            pre[j + 1] = pre[j] + pos[j];
        }
        
        long long ans = LLONG_MAX;
        int mid = k / 2;  // 窗口中位数在窗口内的相对位置
        
        // 枚举每个长度为 k 的窗口，起点 i
        for (int i = 0; i + k <= m; ++i) {
            // 窗口内中位数对应的 q 值：q_mid = pos[i+mid] - mid
            long long qMid = pos[i + mid] - mid;
            
            // 左半部分 [0, mid]：sum(qMid - q_t)
            // sum_{t=0}^{mid} q_t = (pre[i+mid+1] - pre[i]) - (0+1+...+mid)
            long long leftPosSum = pre[i + mid + 1] - pre[i];
            long long leftTSUM = (long long)mid * (mid + 1) / 2;
            long long leftQSum = leftPosSum - leftTSUM;
            long long leftCost = (long long)(mid + 1) * qMid - leftQSum;
            
            // 右半部分 [mid+1, k-1]：sum(q_t - qMid)
            long long rightPosSum = pre[i + k] - pre[i + mid + 1];
            long long rightTSUM = (long long)(mid + 1 + k - 1) * (k - 1 - mid) / 2;
            long long rightQSum = rightPosSum - rightTSUM;
            long long rightCost = rightQSum - (long long)(k - 1 - mid) * qMid;
            
            ans = min(ans, leftCost + rightCost);
        }
        
        return (int)ans;
    }
};
//保序匹配<=交叉匹配，以中间为核心移动更优