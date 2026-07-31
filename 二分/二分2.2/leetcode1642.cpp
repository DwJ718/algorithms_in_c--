#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& dif, int bricks, int ladders, int mid) {
        // 到达建筑物 mid，需要跨越 mid 个间隔
        vector<int> need;
        for (int i = 0; i < mid; i++) {
            if (dif[i] > 0) {
                need.push_back(dif[i]);
            }
        }
        
        sort(need.begin(), need.end(), greater<int>());
        
        long long needBricks = 0;
        for (int i = ladders; i < need.size(); i++) {
            needBricks += need[i];
        }
        
        return needBricks <= bricks;
    }
    
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int len = heights.size();
        if (len == 1) return 0;
        
        vector<int> dif(len - 1);
        for (int i = 0; i < len - 1; i++) {
            dif[i] = max(0, heights[i + 1] - heights[i]);
        }
        
        int l = -1;
        int r = dif.size() + 1;
        
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (check(dif, bricks, ladders, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};