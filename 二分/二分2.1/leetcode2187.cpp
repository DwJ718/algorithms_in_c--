#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& time, int totalTrips, long long m)
    {
        for(auto& x:time)
        {
            totalTrips -= m/x;
            if(totalTrips <= 0)
                return true;
        }
        return false;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        int len = time.size();
        sort(time.begin(),time.end());
        //开区间好写感觉，那就+1，-1
        long long l = time[0] - 1;
        long long r =1LL*time[0]*totalTrips + 1;
        while(l + 1 < r)
        {
            long long m = l + (r - l) / 2;
            if(check(time,totalTrips,m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};