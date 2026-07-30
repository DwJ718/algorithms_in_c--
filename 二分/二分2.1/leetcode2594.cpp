#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int> &ranks, int cars) {
        int min_r = *min_element(ranks.begin(), ranks.end());
        long long left = 0, right = 1LL * min_r * cars * cars;
        while (left + 1 < right) { // 开区间
            long long mid = (left + right) / 2, s = 0;
            for (int r : ranks)
                s += sqrt(mid / r) + 1e-9;//加1e-9防止平方数出误差
            (s >= cars ? right : left) = mid;
        }
        return right;
    }
};
//代码中对整数开方，只要整数转浮点没有丢失精度（在 2^53 −1 内），开方出来的整数部分就是正确的。具体可以参考 IEEE 754。