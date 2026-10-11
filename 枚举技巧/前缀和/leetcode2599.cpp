#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        
        // 判断一个单词是否以元音开头且以元音结尾
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        // s[i] = 前 i 个单词中满足条件的个数
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int add = (isVowel(words[i][0]) && isVowel(words[i].back())) ? 1 : 0;
            s[i + 1] = s[i] + add;
        }
        
        // 回答每个查询
        vector<int> ans;
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            ans.push_back(s[right + 1] - s[left]);
        }
        return ans;
    }
};


/*
int x = 10;
// 不捕获，编译错误
auto f1 = []() { return x; };   // 报错：x 未捕获
// 按值捕获（拷贝一份 x）
auto f2 = [x]() { return x; };  // 可以
// 按引用捕获（用外面的 x 本身）
auto f3 = [&x]() { return x; }; 
// 捕获所有外部变量（按值）
auto f4 = [=]() { return x; };
// 捕获所有外部变量（按引用）
auto f5 = [&]() { return x; };
*/