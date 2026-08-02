#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long gcd(long long x, long long y) {
        return y == 0 ? x : gcd(y, x % y);
    }
    
    long long lcm(long long x, long long y) {
        // 防止溢出
        long long g = gcd(x, y);
        if (x / g > LLONG_MAX / y) return LLONG_MAX;  // 溢出保护
        return x / g * y;
    }
    
    // 计算 ≤ x 的金额数量
    long long count(long long x, vector<int>& coins) {
        int m = coins.size();
        long long total = 0;
        
        // 枚举所有非空子集 (1 到 2^m - 1)
        for (int mask = 1; mask < (1 << m); mask++) {
            long long lcm_val = 1;
            int bits = 0;
            
            // 计算当前子集的 lcm
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    lcm_val = lcm(lcm_val, coins[i]);
                    if (lcm_val > x) break;  // 剪枝：超过 x 就不用继续了
                    bits++;
                }
            }
            
            if (lcm_val > x) continue;  // 这个子集的 lcm 太大，贡献为 0
            
            // 容斥原理：奇数个元素加，偶数个元素减
            if (bits % 2 == 1) {
                total += x / lcm_val;
            } else {
                total -= x / lcm_val;
            }
        }
        
        return total;
    }
    
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // 二分查找
        long long left = 0;
        long long right = (long long)*min_element(coins.begin(), coins.end()) * k;
        // 实际上可以更精确，但为了安全，可以设大一点
        right = min(right, (long long)1e18);  // 防止溢出
        
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            if (count(mid, coins) >= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};

/*
<< 是左移运算符，表示将二进制数向左移动指定位数。
1 << 0 = 1      // 二进制: 1
1 << 1 = 2      // 二进制: 10
1 << 2 = 4      // 二进制: 100
1 << 3 = 8      // 二进制: 1000
1 << 4 = 16     // 二进制: 10000
通用公式：1 << m = 2^m
所以 (1 << m) 就是 2^m。


位运算符总结
运算符	名称	  说明	                            示例
<<	   左移	     左移 n 位，相当于乘以 2^n	         1 << 3 = 8
>>	   右移	     右移 n 位，相当于除以 2^n	         8 >> 3 = 1
&	   按位与	  两个位都是 1 结果为 1	             5 & 3 = 1 (101 & 011 = 001)
|	   按位或	  至少一个位是 1 结果为 1	         5 | 3 = 7 (101 | 011 = 111)
^	   按位异或	  两个位不同结果为 1	              5 ^ 3 = 6 (101 ^ 011 = 110)
~	   按位取反	  0 变 1，1 变 0	                 ~5 = -6




常用位运算技巧
设置第 i 位为 1
mask |= (1 << i);
清除第 i 位（设为 0）
mask &= ~(1 << i);
翻转第 i 位
mask ^= (1 << i);
检查第 i 位是否为 1
if (mask & (1 << i)) { ... }
获取最低位的 1
int lowest = mask & -mask;
// 例如: mask=12(1100), -mask=...0100, 结果为4(0100)
清除最低位的 1
mask &= mask - 1;
// 例如: mask=12(1100), mask-1=11(1011), 结果为8(1000)
*/