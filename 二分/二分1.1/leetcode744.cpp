#include<bits/stdc++.h>
using namespace std;
class Solution {
    int lower_bound(vector<char>& letters,char target)
    {
        int l = -1;
        int r = letters.size();
        int mid;
        while(l + 1 < r)
        {
            mid = l + (r - l)/2;
            if(letters[mid] - target < 1)
                l = mid;
            else 
                r = mid;
        }
        return r;
    }
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int index = lower_bound(letters,target);
        return index < letters.size() ? letters[index] : letters[0];
    }
};

int main() {
   return 0;
}