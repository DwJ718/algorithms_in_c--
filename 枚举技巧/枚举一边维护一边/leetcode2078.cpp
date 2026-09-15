#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {
   return 0;
}


class Solution {
public:
    int maxDistance(vector<int>& colors) {
    //the first or the last may be chosen(if color different)
    int r = colors.size() - 1;
    int l = 0;
    while(colors[r] == colors[0])
        r--;
    while(colors[l] == colors[colors.size() - 1])
        l++;
    return max(r,(int)colors.size() - 1 - l);
    }
};