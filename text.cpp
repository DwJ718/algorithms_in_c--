#include<bits/stdc++.h>
using namespace std;
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        for(int i = 0; i < n; i++)
        {
            if(hours[i] > 8)
                hours[i] = 1;
            else
                hours[i] = -1;
        }
        //dp?
        /*
        dp[i] = max(dp[i - 1], dp[i - 1] + 1 , 0)?;
        can not
        */
        int first = 0,last = 0;
        int flag_1 = 1;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += hours[i];
            hours[i] = sum;
            if(hours[i] > 0)
            {
                if(flag_1)
                {
                    first = i;
                    flag_1 = 0;
                }
                last = i;
            }
        }
        cout << first << " " << last << endl;
        return last - first + 1;
    }
int main() {
    vector<int> hours = {9,9,6,0,6,6,0,9};
    int ans = longestWPI(hours);
    return 0;
}