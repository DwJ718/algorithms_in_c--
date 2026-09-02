#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {
   return 0;
}

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        //Q:只要能被整除就配对
        //记录求余的值
        unordered_map<int,int> cnt;
        int rec = arr.size()/2;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            cnt[(arr[i] % k + k) % k]++;
            if((arr[i] % k + k) % k != 0 && cnt[k - ((arr[i] % k + k) % k)] > 0)
            {
                cnt[(arr[i] % k + k) % k]--;
                cnt[k -((arr[i] % k + k) % k)]--;
                if(cnt[(arr[i] % k + k) % k] >= 0)
                    rec--;
                else
                    cnt[k -((arr[i] % k + k) % k)] += 2;

            }
        }
        rec -= cnt[0]/2;
        return rec == 0;
    }
};


//

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k, 0);  // 用数组代替哈希表
        // 统计余数
        for(int num : arr) {
            int remainder = ((num % k) + k) % k;//负数求正余数
            cnt[remainder]++;
        }
        // 检查配对
        for(int i = 1; i < k; i++) {
            if(cnt[i] != cnt[k - i]) return false;
        }
        
        return cnt[0] % 2 == 0;
    }
};