#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(vector<int>& start, int d, int mid) {
        long long last = start[0]; 
        for (int i = 1; i < start.size(); i++) {
            long long cur = max((long long)start[i], last + mid);
            if (cur > (long long)start[i] + d) {
                return false;
            }
            last = cur;
        }
        return true;
    }
    
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size();
        
        long long l = 0; 
        long long r = (long long)start[n-1] + d - start[0] + 1;  
        
        while (l + 1 < r) {
            long long mid = l + (r - l) / 2;
            if (check(start, d, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        return (int)l;
    }
};