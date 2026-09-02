#include<bits/stdc++.h>
using namespace std;
    bool canArrange(vector<int>& arr, int k) {
        //Q:只要能被整除就配对
        //记录求余的值
        unordered_map<int,int> cnt;
        int rec = arr.size()/2;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            cnt[arr[i] % k]++;
            if(cnt[k - (arr[i] % k)] != 0)
            {
                cnt[arr[i] % k]--;
                cnt[k -(arr[i] % k)]--;
                if(cnt[arr[i] % k] >= 0)
                  rec--;
            }
            cout << "rec = " << rec << endl;
        }
        rec -= cnt[0]/2;
        cout << "rec = " << rec << endl;
        return rec==0;
    }
int main() {
   vector<int> arr = {3,8,17,2,5,6};
   int k = 10;
   bool result = canArrange(arr, k);
   return 0;
}