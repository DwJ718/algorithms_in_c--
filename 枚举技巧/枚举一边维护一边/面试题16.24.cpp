#include<bits/stdc++.h>
using namespace std;
int main() {
   return 0;
}

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> cnt;
        vector<vector<int>> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // 检查是否存在配对的数
            if(cnt.find(complement) != cnt.end() && cnt[complement] > 0) {
                cnt[complement]--;
                ans.push_back({complement, nums[i]});
                if(cnt[complement] == 0) {
                    cnt.erase(complement);
                }
            } else {
                // 当前数不能配对时，才加入哈希表
                cnt[nums[i]]++;
            }
        }
        return ans;
    }
};