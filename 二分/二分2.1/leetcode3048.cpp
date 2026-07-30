#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canFinish(const vector<int>& nums, const vector<int>& changeIndices, int time) {
        int n = nums.size();
        
        // 记录每个下标最后出现的位置
        vector<int> lastPos(n, -1);
        for (int i = 0; i < time; i++) {
            lastPos[changeIndices[i] - 1] = i;
        }
        
        // 检查是否所有下标都出现了
        for (int i = 0; i < n; i++) {
            if (lastPos[i] == -1) return false;
        }
        
        // 贪心验证
        vector<bool> marked(n, false);
        long long freeTime = 0;
        
        for (int i = 0; i < time; i++) {
            int idx = changeIndices[i] - 1;
            
            if (lastPos[idx] == i) {
                if (freeTime < nums[idx]) return false;
                freeTime -= nums[idx];
                marked[idx] = true;
            } else {
                freeTime++;
            }
        }
        
        // 检查是否所有下标都被标记了
        for (int i = 0; i < n; i++) {
            if (!marked[i]) return false;
        }
        
        return true;
    }
    
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        
        // 先特判：如果全部时间都不够，直接返回 -1
        if (!canFinish(nums, changeIndices, m)) {
            return -1;
        }
        // 二分查找最早时间（开区间写法）
        int l = 0, r = m;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (canFinish(nums, changeIndices, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};