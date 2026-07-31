#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        long long sum = 0;
        for (int b : batteries) sum += b;
        
        long long left = 0;
        long long right = sum / n + 1; 
        
        while (left + 1 < right) {
            // 这里用 mid = (left + right + 1) / 2 是为了取右中位数，防止死循环
            long long mid = left + (right - left)/ 2;
            
            // 检查 mid 分钟是否可行
            long long total = 0;
            for (int b : batteries) {
                total += min((long long)b, mid);
                // 一个小优化：如果已经超过 n * mid，提前退出，防止溢出
                if (total >= n * mid) break;
            }
            
            if (total >= n * mid) {
                left = mid; // 可行，尝试更大的时间
            } else {
                right = mid; // 不可行，减小时间
            }
        }
        return left;
    }
};