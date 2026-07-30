#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& order, vector<int>& str, int k, int mid, string s) {
        for (int i = 0; i <= mid; i++)
            str[order[i]] =
                mid; // 当mid为0时，str[x]原本初始化值和mid赋值的区别不开，所以初始化str为-1
        int cnt = 0;
        int last = -1; // 上一个'*'
        for (int j = 0; j < order.size(); j++) {
            if (str[j] == mid)
                last = j;
            cnt += last + 1;
            if (cnt >= k)
                return true;
        }
        return false;
    }

public:
    int minTime(string s, vector<int>& order, int k) {
        // (1 + n)*n/2
        int len = order.size();
        if (1LL * 2 * k > 1LL * len * (len + 1))
            return -1;
        vector<int> str(len, -1);
        int l = -1;
        int r = len - 1; //(t=0也是时间所以要-1)
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            (check(order, str, k, mid, s) ? r : l) = mid;
        }
        return r;
    }
};
//核心是这个str数组，对于每个尝试的取值mid，通过让str[x] = mid来存mid的星然后检查就能用==mid来检查，每个mid都不一样，只需要改动str的数值就可以实现判断