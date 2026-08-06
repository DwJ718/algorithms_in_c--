#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

/*class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<int> index;
        // 1. 找到所有等于 key 的下标
        for(int i = 0; i < n; i++) {
            if(nums[i] == key)
                index.push_back(i);
        }
        // 2. 对每个 key 下标，扩展区间 [t-k, t+k]
        for(int t : index) {
            int left = max(0, t - k);      
            int right = min(n, t + k + 1); 
            
            for(int i = left; i < right; i++) {
                ans.push_back(i);
            }
        }
        // 3. 排序 + 去重
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};*/

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int last = -k - 1; // 保证 key 不存在时 last < i-k
        for (int i = k - 1; i >= 0; i--) {
            if (nums[i] == key) {
                last = i;
                break;
            }
        }
        //第一个区间越后面找到key覆盖范围越广
        //第二个区间相当于全搜索了

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i + k < nums.size() && nums[i + k] == key) {
                last = i + k;
            }
            if (last >= i - k) { // key 在窗口中
                ans.push_back(i);
            }
        }
        return ans;
    }
};