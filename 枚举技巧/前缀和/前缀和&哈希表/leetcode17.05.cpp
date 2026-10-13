#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        unordered_map<int, int> firstPos; // prefix sum -> 最早出现的下标(用 i+1 表示，代表前 i 个元素)
        firstPos[0] = 0; // 空前缀，位置 0，对应下标 -1

        int diff = 0;
        int bestLen = 0, bestStart = 0;

        for (int i = 0; i < n; i++) {
            if (isalpha((unsigned char)array[i][0]))
                diff += 1;
            else
                diff -= 1;

            int curPos = i + 1; // 表示前 curPos 个元素的前缀和

            if (firstPos.count(diff)) {
                int start = firstPos[diff];       // 前 start 个元素
                int len = curPos - start;
                if (len > bestLen) {
                    bestLen = len;
                    bestStart = start;
                }
            } else {
                firstPos[diff] = curPos;
            }
        }

        if (bestLen == 0) return {};
        return vector<string>(array.begin() + bestStart, array.begin() + bestStart + bestLen);
    }
};