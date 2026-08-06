#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int ans = 0, cover = 0, left = 0;
        for (auto& tile : tiles) {
            int tl = tile[0], tr = tile[1];
            cover += tr - tl + 1;
            
            int carpet_left = tr - carpetLen + 1; 
            while (tiles[left][1] < carpet_left) {
                cover -= tiles[left][1] - tiles[left][0] + 1;
                left++;
            }
            int uncover = max(carpet_left - tiles[left][0], 0);//相减完全有可能是负数，比如[5,10],L = 10;
            ans = max(ans, cover - uncover);
        }
        return ans;
    }
};