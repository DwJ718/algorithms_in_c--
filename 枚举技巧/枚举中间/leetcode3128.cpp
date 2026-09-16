#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        //枚举拐点即可
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> rowCnt(m, 0), colCnt(n, 0);
        
        // 预处理每行、每列的 1 的个数
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++rowCnt[i];
                    ++colCnt[j];
                }
            }
        }
        
        long long ans = 0;
        
        // 枚举每个 1 作为直角顶点
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans += (long long)(rowCnt[i] - 1) * (colCnt[j] - 1);
                }
            }
        }
        
        return ans;
    }
};