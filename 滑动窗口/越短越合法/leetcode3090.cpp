#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> cnt(26,0);
        int n = s.size();
        int l = 0;
        int max_l = INT_MIN;
        for(int r = 0;r < n;r++)
        {
            cnt[(s[r] - 'a')]++;
            while(cnt[(s[r] - 'a')] > 2)
            {
                cnt[s[l] - 'a']--;
                l++;
            }
            max_l = max(r-l+1,max_l);
        }
        return max_l;
    }
};