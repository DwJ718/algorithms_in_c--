#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {
   return 0;
}


class Solution {
    // 顺时针旋转矩阵 90°（用于把"垂直分割"转成"水平分割"统一处理）
    vector<vector<int>> rotate(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b[j][m - 1 - i] = a[i][j];
            }
        }
        return b;
    }

    // 把矩阵上下翻转（原地修改）
    void reverseRows(vector<vector<int>>& a) {
        int m = a.size();
        for (int i = 0; i < m / 2; i++) {
            swap(a[i], a[m - 1 - i]);
        }
    }

    // 在"当前方向"下，尝试从上往下枚举分割线，判断能否删一个数使两边相等
    // 返回 true 表示找到合法分割
    // total 是整个矩阵的总和（用于 O(1) 计算另一部分的和）
    bool scan(vector<vector<int>>& a, long long total) {
        int m = a.size(), n = a[0].size();

        // st 存"上半部分中可以被删除的格子的值"
        // 初始放 0，表示"不删除任何格子"这一选项
        unordered_set<long long> st;
        st.insert(0);

        long long s = 0; // 上半部分当前的和（逐行累加）

        // i 是当前分割线所在行（上半部分包含第 0..i 行）
        // 分割线在第 i 行下方，所以上半部分至少 1 行，下半部分至少 1 行
        for (int i = 0; i < m - 1; i++) {
            vector<int>& row = a[i];

            // 把第 i 行所有元素累加进上半部分的和
            for (int j = 0; j < n; j++) {
                int x = row[j];
                s += x;

                // 决定第 i 行的元素能否作为"被删除的候选"
                //
                // 连通性规则：
                //  - 若上半部分有多行（i > 0），删任意一个格子都连通，全部可加入 st
                //  - 若上半部分只有一行（i == 0），删中间格子会把该行切成两段，
                //    只有删这一行的两端（j == 0 或 j == n-1）才保持连通
                if (i > 0 || j == 0 || j == n - 1) {
                    st.insert(x);
                }
            }

            // 特殊情况：只有一列（n == 1）
            // 此时上半部分是一个竖条，删中间格子会断开，只能删两端
            // 上半部分的两端是 a[0][0]（顶）和 a[i][0]（分割线处）
            if (n == 1) {
                // s*2 == total         -> 不删就相等
                // s*2 - total == a[0][0] -> 删顶部
                // s*2 - total == row[0]  -> 删分割线处（当前行的唯一元素）
                if (s * 2 == total ||
                    s * 2 - total == a[0][0] ||
                    s * 2 - total == row[0]) {
                    return true;
                }
                continue;
            }

            // 一般情况：
            // 上半部分和 s，下半部分和 total - s
            // 若从上半部分删掉一个值 v，需要 s - v == total - s
            // 即 v == 2*s - total
            // 所以查 st 中是否存在 (2*s - total)
            if (st.count(s * 2 - total)) {
                return true;
            }

            // 当分割线继续往下移（i 增大）后，上半部分不再是"只有一行"，
            // 此时第 0 行的中间元素也变得可以删除（因为上面还有别的行，删它不影响连通）
            // 所以在 i == 0 处理完后，把第 0 行所有元素补进 st
            if (i == 0) {
                for (int x : row) {
                    st.insert(x);
                }
            }
        }
        return false;
    }

    // 在当前矩阵方向下，检查"水平分割"是否可行
    // 做法：先从上往下扫（删除上半部分的格子），再把矩阵上下翻转后扫（删除下半部分的格子）
    bool check(vector<vector<int>> a, long long total) {
        if (scan(a, total)) {
            return true;
        }
        reverseRows(a);   // 上下翻转，等价于从下往上扫
        return scan(a, total);
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // 计算整个矩阵的总和
        long long total = 0;
        for (vector<int>& row : grid) {
            for (int x : row) {
                total += x;
            }
        }

        // 水平分割：直接检查
        if (check(grid, total)) {
            return true;
        }

        // 垂直分割：把矩阵旋转 90°，垂直分割就变成了"水平分割"，复用同一套逻辑
        vector<vector<int>> rotated = rotate(grid);
        return check(rotated, total);
    }
};