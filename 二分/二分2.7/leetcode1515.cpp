#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 计算到所有点的欧几里得距离之和
    double totalDistance(double x, double y, vector<vector<int>>& positions) {
        double sum = 0;
        for (auto& p : positions) {
            double dx = x - p[0];
            double dy = y - p[1];
            sum += sqrt(dx * dx + dy * dy);
        }
        return sum;
    }
    
    // 固定 y，在 x 方向三分
    double ternarySearchX(double y, vector<vector<int>>& positions, 
                          double left, double right) {
        for (int iter = 0; iter < 80; iter++) {
            double m1 = left + (right - left) / 3;
            double m2 = right - (right - left) / 3;
            
            double d1 = totalDistance(m1, y, positions);
            double d2 = totalDistance(m2, y, positions);
            
            if (d1 < d2) {
                right = m2;
            } else {
                left = m1;
            }
        }
        return (left + right) / 2;
    }
    
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        // 确定搜索范围
        double x_min = 0, x_max = 100;
        double y_min = 0, y_max = 100;
        
        // 外层三分：在 y 方向搜索
        double bottom = y_min, top = y_max;
        
        for (int iter = 0; iter < 80; iter++) {
            double y1 = bottom + (top - bottom) / 3;
            double y2 = top - (top - bottom) / 3;
            
            // 对每个 y，在 x 方向找到最优的 x
            double x1 = ternarySearchX(y1, positions, x_min, x_max);
            double x2 = ternarySearchX(y2, positions, x_min, x_max);
            
            double d1 = totalDistance(x1, y1, positions);
            double d2 = totalDistance(x2, y2, positions);
            
            if (d1 < d2) {
                top = y2;
            } else {
                bottom = y1;
            }
        }
        
        double y_opt = (bottom + top) / 2;
        double x_opt = ternarySearchX(y_opt, positions, x_min, x_max);
        
        return totalDistance(x_opt, y_opt, positions);
    }
};
//二分用于单调函数（找零点），三分用于单峰函数（找极值）。
/*
为什么嵌套三分对二维凸函数有效？
数学依据
定理：如果 f(x,y) 是凸函数，那么：
对任意固定的 y，g(x) = f(x,y) 是 x 的凸函数
对任意固定的 x，h(y) = f(x,y) 是 y 的凸函数
F(y) = min_x f(x,y) 是 y 的凸函数
所以：
内层三分能找到固定 y 下的最优 x
外层三分能在 y 方向上找到使 F(y) 最小的 y
*/