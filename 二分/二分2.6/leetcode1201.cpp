#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long gcd(long long x, long long y) {
        return y == 0 ? x : gcd(y, x % y);
    }
    
    long long lcm(long long x, long long y) {
        // 防止溢出：如果 x/gcd > 2e9/y，说明会超过结果范围
        long long g = gcd(x, y);
        if (x / g > 2e9 / y) {
            return 2e9 + 1;  // 返回一个足够大的数
        }
        return x / g * y;
    }
    
    bool check(long long mid, int n, int a, int b, int c,
               long long lcm_ab, long long lcm_ac, long long lcm_bc, long long lcm_abc) {
        long long count = mid / a + mid / b + mid / c
                        - mid / lcm_ab - mid / lcm_ac - mid / lcm_bc
                        + mid / lcm_abc;
        return count >= n;
    }
    
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // 预计算所有 lcm，处理溢出
        long long lcm_ab = lcm(a, b);
        long long lcm_ac = lcm(a, c);
        long long lcm_bc = lcm(b, c);
        long long lcm_abc = lcm(lcm_ab, c);
        
        // 如果 lcm_abc 太大，设为 2e9+1，这样 mid/lcm_abc 为 0
        if (lcm_abc > 2e9) lcm_abc = 2e9 + 1;
        
        // 二分边界 - 利用题目保证的结果范围
        long long left = 0;
        long long right = 2e9 + 1;  // 结果最大 2e9，+1 确保是开区间
        
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid, n, a, b, c, lcm_ab, lcm_ac, lcm_bc, lcm_abc)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        return (int)right;
    }
};