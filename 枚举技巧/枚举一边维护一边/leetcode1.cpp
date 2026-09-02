#include<bits/stdc++.h>
using namespace std;
int main() {
   return 0;
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //n^2是很容易想的
        //遍历一遍有没有可能？
        unordered_map<int,int> mp;
        for(int i = 0 ; ; i++)
        {
            auto it = mp.find(target - nums[i]);
            if(it != mp.end())
                return {it->second,i};
            mp[nums[i]] = i;
        }
    }
};