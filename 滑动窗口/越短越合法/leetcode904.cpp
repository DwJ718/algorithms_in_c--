#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> cnt;

        int l = 0;
        int max_l = 0;
        int n = fruits.size();
        for(int r = 0 ; r < n ; r++)
        {
            cnt[fruits[r]]++;
            while(cnt.size() > 2)
            {
                cnt[fruits[l]]--;
                if(cnt[fruits[l]] == 0)
                    cnt.erase(fruits[l]);
                l++;
            }
            max_l = max(r - l + 1,max_l);
        }
        return max_l;
    }
};