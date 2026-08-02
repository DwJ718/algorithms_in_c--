#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 计算最大公约数
    long long gcd(long long x, long long y) {
        return y == 0 ? x : gcd(y, x % y);
    }
    
    // 计算最小公倍数
    long long lcm(long long x, long long y) {
        return x / gcd(x, y) * y;
    }
    
    // 检查 mid 是否为第 n 个神奇数字（或更大）
    bool check(long long mid, int n, int a, int b, long long lcm_ab) {
        long long count = mid / a + mid / b - mid / lcm_ab;
        return count >= n;
    }
    
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int MOD = 1000000007;
        
        // 预计算 lcm
        long long lcm_ab = lcm(a, b);
        
        // 二分边界
        long long left = 0;
        long long right = (long long)min(a, b) * n;  // 精确的上界
        
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid, n, a, b, lcm_ab)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        return right % MOD;
    }
};