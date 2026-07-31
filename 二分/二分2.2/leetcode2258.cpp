#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> fireTime(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        // ========== 第一步：多源BFS计算火到达时间 ==========
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fireTime[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    grid[nx][ny] != 2 && fireTime[nx][ny] == INT_MAX) {
                    fireTime[nx][ny] = fireTime[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        // ========== 第二步：特殊情况判断 ==========
        if (grid[0][0] == 2 || grid[m-1][n-1] == 2) return -1;
        
        // ========== 第三步：判断函数 ==========
        auto canReach = [&](int waitTime) -> bool {
            // 如果起点在等待后已经着火，不可能
            if (fireTime[0][0] <= waitTime) return false;
            
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<tuple<int,int,int>> q2;
            q2.push({0, 0, waitTime});
            visited[0][0] = true;
            
            while (!q2.empty()) {
                auto [x, y, time] = q2.front(); q2.pop();
                
                if (x == m-1 && y == n-1) return true;
                
                for (auto &d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (grid[nx][ny] == 2 || visited[nx][ny]) continue;
                    
                    int nextTime = time + 1;
                    
                    // 终点特殊处理：可以等于火到达时间
                    if (nx == m-1 && ny == n-1) {
                        if (nextTime <= fireTime[nx][ny]) {
                            return true;
                        }
                        continue;
                    }
                    
                    // 普通格子：必须严格小于火到达时间
                    if (nextTime < fireTime[nx][ny]) {
                        visited[nx][ny] = true;
                        q2.push({nx, ny, nextTime});
                    }
                }
            }
            return false;
        };
        
        // ========== 第四步：处理终点永远不着火的情况 ==========
        if (fireTime[m-1][n-1] == INT_MAX) {
            return canReach(0) ? 1e9 : -1;
        }
        
        // ========== 第五步：左开右开区间二分 ==========
        // left: 不可行（-1 分钟肯定不可行，因为时间不能为负）
        // right: 不可行（fireTime[0][0] 分钟时起点着火，肯定不可行）
        int left = -1;                  // 不可行
        int right = fireTime[0][0];     // 不可行
        
        // 但如果 0 分钟本身不可行，直接返回 -1
        if (!canReach(0)) return -1;
        
        // 左开右开区间 (left, right)
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (canReach(mid)) {
                left = mid;      // mid 可行，左边界右移
            } else {
                right = mid;     // mid 不可行，右边界左移
            }
        }
        
        // 循环结束时，left 是最后一个可行的
        return left;
    }
};