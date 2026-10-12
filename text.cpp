#include<bits/stdc++.h>
using namespace std;
    bool canArrange(vector<int>& arr, int k) {
        //Q: 判断能否两两配对，使每对和都能被 k 整除
        //核心：统计余数，r 和 k-r 的个数必须相等
        vector<int> cnt(k, 0);
        for (int x : arr)
            cnt[((x % k) + k) % k]++;   //负数也要转成非负余数

        if (cnt[0] % 2) return false;    //余数 0 必须成对（偶数个）

        for (int r = 1; r < k; r++) {
            if (2 * r == k) {            //r 只能和自己配，个数必须为偶数
                if (cnt[r] % 2) return false;
            } else if (cnt[r] != cnt[k - r]) {
                return false;
            }
        }
        return true;
    }
int main() {
   vector<int> arr = {3,8,17,2,5,6};
   int k = 10;
   bool result = canArrange(arr, k);
   cout << (result ? "true" : "false") << endl;
   return 0;
}