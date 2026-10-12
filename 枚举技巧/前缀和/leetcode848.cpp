#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = shifts.size() - 1 ; i > 0 ; i--)
        {
            shifts[i] %= 26;
            s[i] = 'a' + (s[i] - 'a' + shifts[i]) % 26;
            shifts[i - 1] = (shifts[i - 1] + shifts[i]) % 26;
        }
        s[0] = 'a' + (s[0] - 'a' + shifts[0]) % 26;
        return s;
    }
};