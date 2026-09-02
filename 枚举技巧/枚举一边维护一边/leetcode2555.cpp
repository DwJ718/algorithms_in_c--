#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {
   return 0;
}


class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        //枚举第二个线段右端点，看第一个线段最多能有多少
        //礼物数量就是r-l+1,一个坐标就有一个礼物
        int n = prizePositions.size();
        if(k * 2 >= prizePositions[n - 1] - prizePositions[0])
            return n;
        int ans = 0, left = 0;
        vector<int> mx(n + 1);//左线右端点小于等于时的最大奖品数
        for(int right = 0; right < n; right++)
        {
            while(prizePositions[right] - prizePositions[left] > k)//保证比k小，线段左端点可能比prizePositions[left]还小
                left++;
            ans = max(ans, mx[left] + right - left +1);
            mx[right + 1] = max(mx[right], right - left + 1);
        }
        return ans;
    }
};