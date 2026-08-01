#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(int radius, vector<vector<int>>& points, string& s, vector<int>& dist) {
        unordered_set<char> seen;
        for (int i = 0; i < points.size(); i++) {
            if (dist[i] <= radius) {
                if (seen.count(s[i])) return false;
                seen.insert(s[i]);
            }
        }
        return true;
    }
public:
        //如果能包含两个点那一定可以包含一个点，具有单调性
        //问题是怎么判重复
        //点是有横向和纵向距离的，只要其中的举例小于正方形一半那么点就在其中
        //边长也是单调性只会越长或者越短
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        // 计算每个点到原点的切比雪夫距离
        vector<int> dist(n);
        for (int i = 0; i < n; i++) {
            dist[i] = max(abs(points[i][0]), abs(points[i][1]));
        }
        // 二分查找最大的半径
        int left = -1, right = 1e9 + 1;
        int ans = 0;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid, points, s, dist)) {
                ans = mid;
                left = mid;
            } else {
                right = mid;
            }
        }
        // 统计在半径为 ans 的正方形内的点数
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= ans) result++;
        }
        return result;
    }
};



/*
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int min_d[26], min2 = INT_MAX;
        ranges::fill(min_d, INT_MAX);
        for (int i = 0; i < points.size(); i++) {
            int d = max(abs(points[i][0]), abs(points[i][1]));
            char c = s[i] - 'a';
            if (d < min_d[c]) {
                // d 是目前最小的，那么 min_d[c] 是次小的
                min2 = min(min2, min_d[c]);
                min_d[c] = d;
            } else {
                // d 可能是次小的
                min2 = min(min2, d);
            }
        }
        int ans = 0;
        for (int d : min_d) {
            ans += d < min2;
        }
        return ans;
    }
};
用mid_c来存每个的最小值，然后min2存全局的次小，如果有边长大于等于min2那么必会出现两个相同的点
*/