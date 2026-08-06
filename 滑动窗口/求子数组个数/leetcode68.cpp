#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        int n = flowers.size();
        int left = 0;
        long long ans = 0;
        unordered_map<int, int> freq;  // 品种 -> 出现次数
        
        for (int right = 0; right < n; right++) {
            // 1. 加入当前花
            freq[flowers[right]]++;
            
            // 2. 如果该品种数量超过 cnt，移动左指针
            while (freq[flowers[right]] > cnt) {
                freq[flowers[left]]--;
                left++;
            }
            
            // 3. 此时 [left, right] 是合法的
            // 以 right 为右端点的所有合法区间数量 = right - left + 1
            ans += right - left + 1;
        }
        
        return (int)ans;
    }
};