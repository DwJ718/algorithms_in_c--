#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //排序，用二分找大于等于success/spells即可
        sort(potions.begin(),potions.end());
        long long n;
        vector<int> ans;
        for(int i = 0 ; i < spells.size() ; i++ )
        {
            n = (success + spells[i] - 1) / spells[i];//上取整
            ans.push_back(potions.end() - lower_bound(potions.begin(),potions.end(),n));
        }
        return ans;
    }
};
//简单题，但是有更好写法，比如原地修改就省下空间
/*
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ranges::sort(potions);
        for (int& x : spells) { // 原地修改
            long long target = (success - 1) / x;
            if (target < potions.back()) {
                // 这样写每次二分就只用比两个 int 的大小，避免把 potions 中的元素转成 long long 比较
                x = potions.end() - ranges::upper_bound(potions, (int) target);
            } else {
                x = 0;
            }
        }
        return spells;
    }
};

当a为非负整数，b为正整数时，有上下取整转换公式，a/b的上取整等于(a+b-1)/b的下取整
证明思路也很简单，分类讨论a mod b的情况，要么为0要么大于0
*/