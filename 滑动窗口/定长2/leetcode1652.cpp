#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(),0);
        if(k == 0)
            return ans;
        else if(k > 0)
        {
            for(int i = 0 ; i < code.size(); i++)
            {
                for(int j = i; j < i + k; j++)
                    ans[i] += code[(j + 1) % code.size()];
            }
        }
        else
        {
            k *=-1;
            for(int i = code.size() - 1; i >= 0; i--)
            {
                for(int j = i; j > i - k; j--)
                    ans[i] += code[(j - 1 + code.size()) % code.size()];
            }
        }
        return ans;
    }
};