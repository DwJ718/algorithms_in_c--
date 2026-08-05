#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int max_s = INT_MIN;
        int sum = 0;
        
        for(int i = 0 ; i < n; i++)
        {
            sum += nums[i];
            if(i < k - 1)
            {
                continue;
            }
            max_s = max(max_s,sum);
            sum -= nums[i-k+1];
        }
        return (double) max_s / k;
    }
};

/*
这种"先加后减"的模式保证了：

每次循环开始时，窗口大小是 k-1（除了最开始初始化阶段）

加上新元素后变成 k，这时更新答案

再减去最左边元素，又回到 k-1，为下一轮做准备
*/