#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int) {
        unordered_map<string, int> str_cnt;
        int char_cnt[26]{};
        int kinds = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            // 1. 进入窗口
            int in = s[i] - 'a';
            if (char_cnt[in] == 0) {
                kinds++;
            }
            char_cnt[in]++;

            int left = i - minSize + 1;
            if (left < 0) { // 窗口大小不足 minSize
                continue;
            }

            // 2. 更新统计量
            if (kinds <= maxLetters) {
                int cnt = ++str_cnt[s.substr(left, minSize)];
                ans = max(ans, cnt);
            }

            // 3. 离开窗口，为下一个循环做准备
            int out = s[left] - 'a';
            char_cnt[out]--;
            if (char_cnt[out] == 0) {
                kinds--;
            }
        }

        return ans;
    }
};