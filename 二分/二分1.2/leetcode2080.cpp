#include<bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
    unordered_map<int,vector<int>> pos;
public:
    RangeFreqQuery(vector<int>& arr) 
    {
        for(int i = 0 ; i < arr.size() ; i++)
            pos[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) 
    {
        auto it = pos.find(value);
        if(it == pos.end())
            return 0;
        auto& a = it->second;
        return upper_bound(a.begin(),a.end(),right) - lower_bound(a.begin(),a.end(),left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

 //转换思路用下标来二分，如果对每个[l.r]里的数排序再二分那肯定超时，数组的核心就是数字和下标