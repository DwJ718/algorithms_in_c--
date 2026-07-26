#include<bits/stdc++.h>//万能头文件
using namespace std;

int floor_log2(unsigned int n) {
    int result = -1;
    while (n) {
        n >>= 1;
        result++;
    }
    return result;
}
int main() {
    int a = 8;
    cout << log2(a) << endl;
    cout << floor_log2(a) << endl;
    cout << __lg(a) << endl;
   return 0;
}