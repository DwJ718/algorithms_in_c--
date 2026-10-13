#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;

        unordered_map<int, int> firstPos;  // 余数 -> 首次出现的下标
        firstPos[0] = -1;                  // 空前缀，位置 -1，表示"和的前面什么都没有"

        int prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % k;

            if (firstPos.count(prefix)) {
                // 之前出现过相同余数，两点之间(不含左端点)区间长度 = i - firstPos[prefix]
                if (i - firstPos[prefix] >= 2)
                    return true;
            } else {
                firstPos[prefix] = i;  // 只记第一次
            }
        }
        return false;
    }
};