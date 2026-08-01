#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& position,int m,int mid)
    {
        int start = position[0];
        m--;
        for(int i = 1 ; i < position.size(); i++)
        {
            if(start + mid <= position[i])
            {
                start = position[i];
                m--;
            }
            if(m == 0)
                return true;
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l = 0;
        int r = position[position.size() - 1] - position[0] + 1;
        //球放第一个应该是完全可以的，从第一个开始往后面放
        //我们或许可以这样思考，对于给定的磁力，我们怎么放这么多球，为了尽可能满足那第一个位置的球是必须的
        while(l + 1 < r)
        {
            int mid = l + (r - l)/2;
            if(check(position,m,mid))
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};