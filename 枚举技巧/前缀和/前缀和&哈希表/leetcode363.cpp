#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;

        for (int top = 0; top < m; top++) {
            vector<int> colSum(n, 0);
            for (int bottom = top; bottom < m; bottom++) {
                // 累加第 bottom 行到 colSum
                for (int j = 0; j < n; j++) {
                    colSum[j] += matrix[bottom][j];
                }

                // 一维问题：在 colSum 中找不超过 k 的最大子数组和
                set<int> prefixSet = {0};
                int s = 0;
                for (int j = 0; j < n; j++) {
                    s += colSum[j];
                    // 找 pre >= s - k
                    auto it = prefixSet.lower_bound(s - k);
                    if (it != prefixSet.end()) {
                        ans = max(ans, s - *it);
                    }
                    prefixSet.insert(s);
                }
            }
        }
        return ans;
    }
};