#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}
/*class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = l; i <= r; i++) {
            int tmp = 0;
            int ll = 0;
            for (int rr = 0; rr < n; rr++) {
                tmp += nums[rr];
                while (rr - ll >= i) {
                    tmp -= nums[ll];
                    ll++;
                }
                if (rr - ll + 1 == i && tmp > 0)
                    ans = min(ans, tmp);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
*/
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        multiset<long long> st;
        int ans = INT_MAX;

        // j 是右端点（对应 pre[j]），i ∈ [j-r, j-l]
        for (int j = l; j <= n; j++) {
            // 新增 i = j - l 进入窗口
            st.insert(pre[j - l]);
            // 移除 i = j - r - 1 离开窗口
            if (j - r - 1 >= 0) {
                st.erase(st.find(pre[j - r - 1]));
            }
            // 在 st 中找 < pre[j] 的最大值
            auto it = st.lower_bound(pre[j]);
            if (it != st.begin()) {
                --it;
                long long s = pre[j] - *it;  // s > 0
                if (s < ans) ans = (int)s;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
//前缀和与下标要区分开