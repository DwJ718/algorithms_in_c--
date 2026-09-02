#include<bits/stdc++.h>
using namespace std;
int main() {
   return 0;
}


class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> cnt;
        long long ans = 0;
        for(auto& s : words)
        {
            char cur = s[0];
            for(auto& c : s)
            {
                c = (c - cur + 26) % 26;
            }
            ans += cnt[s];
            cnt[s]++;
        }
        return ans;
    }
};