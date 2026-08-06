#include<bits/stdc++.h>//万能头文件
using namespace std;
#define M_PI 3.14159265358979323846
int main() {

   return 0;
}

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int posx = location[0], posy = location[1];
        int base = 0;
        vector<double> angles;
        const double eps = 1e-9;
        
        // 1. 计算角度
        for (auto& p : points) {
            int dx = p[0] - posx;
            int dy = p[1] - posy;
            
            if (dx == 0 && dy == 0) {
                base++;
                continue;
            }
            
            double deg = atan2(dy, dx) * 180.0 / M_PI;
            angles.push_back(deg);
        }
        
        // 2. 排序
        sort(angles.begin(), angles.end());
        
        // 3. 复制 + 360°
        int n = angles.size();
        for (int i = 0; i < n; i++) {
            angles.push_back(angles[i] + 360.0);
        }
        
        // 4. 滑动窗口（加 eps）
        int ans = 0;
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r < angles.size() && angles[r] - angles[l] <= angle + eps) {
                r++;
            }
            ans = max(ans, r - l);
        }
        
        return base + ans;
    }
};

//-180 + 360 = 80