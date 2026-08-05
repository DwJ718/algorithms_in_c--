#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int max_s = 0, s = 0, cnt = 0;
        for (int i = 0; i < n + k; ++i) {
            int in = i % n;
            s += cardPoints[in];
            if (in == 0 || in == n - 1) cnt++;
            if (i < k - 1) continue;
            if (cnt) max_s = max(max_s, s);
            int out = (i - k + 1) % n;
            s -= cardPoints[out];
            if (out == 0 || out == n - 1) cnt--;
        }
        return max_s;
    }
};

//下面两个一个反向一个正向思考
/*class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;
        int s = reduce(cardPoints.begin(), cardPoints.begin() + m);
        int min_s = s;
        for (int i = m; i < n; i++) {
            s += cardPoints[i] - cardPoints[i - m];
            min_s = min(min_s, s);
        }
        return reduce(cardPoints.begin(), cardPoints.end()) - min_s;
    }
};*/


/*class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int s = reduce(cardPoints.begin(), cardPoints.begin() + k);
        int ans = s;
        for (int i = 1; i <= k; i++) {
            s += cardPoints[cardPoints.size() - i] - cardPoints[k - i];
            ans = max(ans, s);
        }
        return ans;
    }
};*/