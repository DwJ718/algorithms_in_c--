#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long gcd(long a, long b)
    {
        if (!b)
            return a;
        return gcd(b, a % b);
    }
    // 计算最小公倍数
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    
    // 判断在limit范围内是否可行
    bool can(int limit, int divisor1, int divisor2, 
             int uniqueCnt1, int uniqueCnt2) {
        // 1到limit的总数
        long long total = limit;
        
        // 能被arr1接受的数字（不能被divisor1整除）
        long long can1 = total - total / divisor1;
        
        // 能被arr2接受的数字（不能被divisor2整除）
        long long can2 = total - total / divisor2;
        
        // 能被两者同时接受的数字
        long long l = lcm(divisor1, divisor2);
        long long both_can = total - total / divisor1 - total / divisor2 + total / l;
        
        // 只能放arr1的数字
        long long only1 = can1 - both_can;
        
        // 只能放arr2的数字
        long long only2 = can2 - both_can;
        
        // 检查arr1是否有足够的数字
        if (can1 < uniqueCnt1) return false;
        
        // 检查arr2是否有足够的数字
        if (can2 < uniqueCnt2) return false;
        
        // arr1需要从公共数字中拿多少
        long long need1 = max(0LL, (long long)uniqueCnt1 - only1);
        
        // arr2需要从公共数字中拿多少
        long long need2 = max(0LL, (long long)uniqueCnt2 - only2);
        
        // 公共数字是否足够满足两边的需求
        return both_can >= need1 + need2;
    }
    
public:
    int minimizeSet(int divisor1, int divisor2, 
                    int uniqueCnt1, int uniqueCnt2) {
        // 左闭右开区间 [left, right)
        // left: 不可行，right: 可行
        long long left = 0;
        long long right = 2e9;  // 足够大的上限
        
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            if (can(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        return (int)right;
    }
};