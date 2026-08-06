#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, ones = 0;
        int minLen = INT_MAX;
        string ans = "";
        
        for (int r = 0; r < n; r++) {
            if (s[r] == '1') ones++;
            
            // 收缩窗口直到 ones <= k
            while (ones > k) {
                if (s[l] == '1') ones--;
                l++;
            }
            
            // 如果恰好有 k 个 1，尝试收缩左边界以找到更短的子串
            while (ones == k) {
                int len = r - l + 1;
                string sub = s.substr(l, len);
                
                if (len < minLen) {
                    minLen = len;
                    ans = sub;
                } else if (len == minLen && sub < ans) {
                    ans = sub;
                }
                
                // 尝试移动左指针，看看能否找到更短的
                if (s[l] == '1') ones--;
                l++;
            }
        }
        
        return ans;
    }
};