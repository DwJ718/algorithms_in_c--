#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
        int getIndex(char c) {
        if (c == 'Q') return 0;
        if (c == 'W') return 1;
        if (c == 'E') return 2;
        return 3;  // 'R'
    }
    
    bool isBalanced(vector<int>& cnt, vector<int>& window, int target) {
        // 检查窗口外的每种字符是否 ≤ target
        for (int i = 0; i < 4; i++) {
            if (cnt[i] - window[i] > target) {
                return false;
            }
        }
        return true;
    }
public:
    int balancedString(string s) {
        int n = s.size();
        int target = n / 4;
        vector<int> cnt(4, 0);  // Q, W, E, R
        
        // 统计总数
        for (char c : s) {
            cnt[getIndex(c)]++;
        }
        
        // 检查是否已经平衡
        if (cnt[0] == target && cnt[1] == target && 
            cnt[2] == target && cnt[3] == target) {
            return 0;
        }
        
        int ans = n;
        int l = 0;
        vector<int> window(4, 0);
        
        for (int r = 0; r < n; r++) {
            // 扩大窗口：把 s[r] 加入待替换区域
            window[getIndex(s[r])]++;
            
            // 检查窗口外的字符是否都 ≤ target
            while (l <= r && isBalanced(cnt, window, target)) {
                ans = min(ans, r - l + 1);
                // 尝试缩小窗口
                window[getIndex(s[l])]--;
                l++;
            }
        }
        
        return ans;
    }
};