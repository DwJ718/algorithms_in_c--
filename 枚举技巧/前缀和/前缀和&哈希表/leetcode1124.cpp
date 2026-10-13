#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}


class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int,int> firstPos;  // 前缀和 -> 第一次出现的下标
        int pre = 0, ans = 0;
        for (int j = 0; j < n; j++) {
            pre += (hours[j] > 8) ? 1 : -1;
            if (pre > 0) {
                ans = j + 1;              // 从头到 j 整段合法
            } else {
                if (firstPos.count(pre - 1))
                    ans = max(ans, j - firstPos[pre - 1]);
                if (!firstPos.count(pre))
                    firstPos[pre] = j;    // 只记第一次
            }
        }
        return ans;
        //前缀和从 0 开始，而且每次只变 ±1
    }
};