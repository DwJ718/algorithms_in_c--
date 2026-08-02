#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        if (x == 0) return 0;
        
        long long left = 0;
        long long right = (long long)x / 2 + 1;  // 上界
        
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            
            if (mid * mid <= x) {
                left = mid;      // mid 满足条件，尝试更大的
            } else {
                right = mid;     // mid 不满足条件，尝试更小的
            }
        }
        
        return (int)left;
    }
};