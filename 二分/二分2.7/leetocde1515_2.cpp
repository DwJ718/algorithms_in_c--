#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    double totalDistance(double x, double y, vector<vector<int>>& positions) {
        double sum = 0;
        for (auto& p : positions) {
            double dx = x - p[0];
            double dy = y - p[1];
            sum += sqrt(dx * dx + dy * dy);
        }
        return sum;
    }
    
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        int n = positions.size();
        
        // 初始点：所有点的平均值
        double x = 0, y = 0;
        for (auto& p : positions) {
            x += p[0];
            y += p[1];
        }
        x /= n;
        y /= n;
        
        // 先计算一次初始距离，后面用于比较
        double best_dist = totalDistance(x, y, positions);
        
        // Weiszfeld 迭代 - 增加迭代次数
        for (int iter = 0; iter < 500; iter++) {
            double num_x = 0, num_y = 0, denom = 0;
            bool has_zero_distance = false;
            
            for (auto& p : positions) {
                double dx = x - p[0];
                double dy = y - p[1];
                double d = sqrt(dx * dx + dy * dy);
                
                if (d < 1e-12) {  // 更小的阈值
                    has_zero_distance = true;
                    break;
                }
                
                double w = 1.0 / d;
                num_x += w * p[0];
                num_y += w * p[1];
                denom += w;
            }
            
            if (has_zero_distance) {
                return best_dist;
            }
            
            double new_x = num_x / denom;
            double new_y = num_y / denom;
            
            // 更严格的收敛条件
            if (abs(new_x - x) < 1e-10 && abs(new_y - y) < 1e-10) {
                break;
            }
            
            x = new_x;
            y = new_y;
            
            // 可选：每10次迭代检查一次距离改善
            if (iter % 10 == 0) {
                double curr_dist = totalDistance(x, y, positions);
                if (abs(curr_dist - best_dist) < 1e-8) {
                    break;
                }
                best_dist = curr_dist;
            }
        }
        
        return totalDistance(x, y, positions);
    }
};

//Weiszfeld算法