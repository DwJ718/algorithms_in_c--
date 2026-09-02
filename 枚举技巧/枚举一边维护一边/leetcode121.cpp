#include<bits/stdc++.h>
using namespace std;
int main() {
   return 0;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        int mimimi = INT_MAX;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] - mimimi > p)
                p = prices[i] - mimimi;
            mimimi = mimimi < prices[i] ? mimimi : prices[i];
        }
        return p;
    }
};