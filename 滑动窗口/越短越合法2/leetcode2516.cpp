#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int cnt_a = 0;
        int cnt_b = 0;
        int cnt_c = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == 'a')
                cnt_a++;
            else if(s[i] == 'b')
                cnt_b++;
            else
                cnt_c++;
        }
        if(cnt_a < k || cnt_b < k || cnt_c < k)
            return -1;
        cnt_a -= k;
        cnt_b -= k;
        cnt_c -= k;
        int max_l = 0;
        int l = 0;
        for(int j = 0 ; j < n; j++)
        {
            if(s[j] == 'a')
                cnt_a--;
            else if(s[j] == 'b')
                cnt_b--;
            else
                cnt_c--;
            while(cnt_a < 0 || cnt_b < 0 || cnt_c < 0)
            {
                if(s[l] == 'a')
                    cnt_a++;
                else if(s[l] == 'b')
                    cnt_b++;
                else
                    cnt_c++;
                l++;
            }
            max_l = max(j - l + 1,max_l);
        }
        return n - max_l;
    }
};

/*
class Solution {
public:
    int takeCharacters(string s, int k) {
        int cnt[3]{};
        for (char c : s) {
            cnt[c - 'a']++; // 一开始，把所有字母都取走
        }
        if (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
            return -1; // 字母个数不足 k
        }

        int mx = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            int c = s[right] - 'a';
            cnt[c]--; // 移入窗口，相当于不取走 c
            while (cnt[c] < k) { // 窗口之外的 c 不足 k
                cnt[s[left] - 'a']++; // 移出窗口，相当于取走 s[left]
                left++;
            }
            mx = max(mx, right - left + 1);
        }
        return s.length() - mx;
    }
};

*/