#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> cnt(26,0);

        for(int i = 1 ; i < n ; i++)
        {
            cnt[s[i] - 'a']++;
        }

        vector<int> pre(26,0);
        vector<vector<int>> kkk(26,vector<int>(26));
        int ans = 0;

        for(int i = 1 ; i < n - 1 ; i++)
        {
            int mid = s[i] - 'a';
            cnt[mid]--;
            pre[s[i - 1] - 'a']++;
            for(int f = 0 ; f < 26; f++)
            {
                if(pre[f] && cnt[f] && !kkk[mid][f])
                {
                    kkk[mid][f]++;
                    ans++;
                }
            }
        }
        return ans;
    }
};