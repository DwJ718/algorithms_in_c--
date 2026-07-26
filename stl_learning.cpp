#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {
   vector<int> v = {1, 2, 3, 4, 5};
   int sum = accumulate(v.begin(), v.end(), 0);
   cout << "Sum: " << sum << endl;
   return 0;
}

//c++标准模板库包含四个组件算法，容器，仿函数，迭代器
/*
顺序容器: vector,array,deque,list,forward_list

关联容器：set,map,multiset,multimap

无序关联容器：unordered_set,unordered_map,unordered_mutiset,unordered_mutimap

容器适配器：stack,queue,pirority_queue,flat_set,flat_map,flat_multiset,flat_multimap

字符串：string

对与元组：pair,tuple
*/



/*
vector:动态数组
vector<类型>arr(长度，[初值])
   vector<int> arr;
   vector<int> arr(100);
   vector<int> arr(100,1);

   vector<vector<int>> arr(100,vector<int>());
   vector<vector<int>> arr(100,vector<int>(666,-1)); //100行，666列，初值为-1

   常见函数：
   尾接&尾删：arr.push_back(元素)，arr.pop_back()
   快速清空vector：arr.clear()
   判空：arr.empty()
   修改长度：arr.resize(长度，初值)
   长度：arr.size() //.size()返回值类型为 size_t，通常 OJ 平台使用的是 32 位编译器（有些平台例如 cf 可选 64 位），那么该类型范围为 [0,2^{32}].

   一般都可以替换常规数组：
   普通数组 int mat[1000010][1000010]可能会MLE，vector<vector<int>> mat(n+10,vector(m+10))就不会
   vector的数据存储于堆空间中，不会爆栈

   注意：如果长度已经确定，那么应当直接在构造函数指定长度，而不是一个一个 .push_back(). 因为vector额外内存耗尽后的重分配是有时间开销的，直接指定长度就不会出现重分配了。

*/

/*
栈
构造：stack<类型> stk
进站：.push(元素)
出栈：.pop()
取栈顶：.top()
.size(),.empty()

vector 也可以当栈用，vector 的.back()取尾部元素，就相当于取栈顶，.push_back()相当于进栈，.pop_back()相当于出栈。

*/

/*
队列
构造：queue<类型>que
进队：.push(元素)
出队：.pop()
取队首：.front()
取队尾：.back()
.size(),.empty()
*/

/*
优先队列
构造priority_queue<类型，容器，比较器> pque

类型：要储存的数据类型
容器：储存数据的底层容器，默认为 vector<类型>，竞赛中保持默认即可
比较器：比较大小使用的比较器，默认为 less<类型>，可自定义(自定义前，容器那里要写，不能默认)
进队O(log n),取栈顶O(1)
插入维护时klog n,用快排每次插入维护knlog n
只有堆顶可读 pque.top()
*/

/*
集合
提供对数时间的插入、删除、查找的集合数据结构。底层原理是红黑树。
| 集合三要素 | 解释                            | set           | multiset      | unordered_set |
| ---------- | ------------------------------ | ------------- | ------------- | ------------- |
| 确定性     | 一个元素要么在集合中，要么不在    | ✔             | ✔             | ✔             |
| 互异性     | 一个元素仅可以在集合中出现一次    | ✔             | ❌（任意次）   | ✔             |
| 无序性     | 集合中的元素是没有顺序的          | ❌（从小到大） | ❌（从小到大） | ✔             |

构造：set<类型，比较器> st
set<int> st1;               // 储存int的集合（从小到大）
set<int, greater<int>> st2; // 储存int的集合（从大到小）

插入：.insert(元素)
删除：.erase(元素)
查找：.find(元素)
判存：.count(元素)
.size(),.empty()

遍历：
迭代器：for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
            cout << *it << endl;
基于范围的循环（c++11)：for (auto &ele : st)
                           cout << ele << endl;
基本类型（int, char, bool）	     auto ele	          拷贝开销小，代码简洁
大对象（string, vector, 自定义类）	const auto &ele	  避免拷贝，提高性能
需要修改元素（仅 vector/list 等）	auto &ele	        修改原容器元素
关联容器（set, map 的 key）	     const auto &ele	    元素不可修改，且避免拷贝
*/

/*
映射
提供对数时间的有序键值对结构。底层原理是红黑树。

| 性质   | 解释                          | map           | multimap      | unordered_map |
| ------ | ---------------------------- | ------------- | ------------- | ------------- |
| 互异性 | 一个键仅可以在映射中出现一次    | ✔             | ❌（任意次）   | ✔             |
| 无序性 | 键是没有顺序的                 | ❌（从小到大） | ❌（从小到大） | ✔             |

构造：map<键类型, 值类型, 比较器> mp
map<int, int> mp1;               // int->int 的映射（键从小到大）
map<int, int, greater<int>> st2; // int->int 的映射（键从大到小）

遍历
可使用迭代器进行遍历：
for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    cout << it->first << ' ' << it->second << endl;

基于范围的循环（C++ 11）：
for (auto &pr : mp)
    cout << pr.first << ' ' << pr.second << endl;

结构化绑定 + 基于范围的循环（C++17）：
for (auto &[key, val] : mp)
    cout << key << ' ' << val << endl;

增/改/查元素：mp[1] = 1
查元素（返回迭代器）：.find(元素)
删除元素：.erase(元素)
判存：.count(元素)
.size(),.empty()

如果使用中括号访问 map 时对应的键不存在，那么会新增这个键，并且值为默认值，因此中括号会影响键的存在性。
map<char, int> mp;
cout << mp.count('a') << endl; // 0
mp['a'];                       // 即使什么都没做，此时mp['a']=0已经插入了
cout << mp.count('a') << endl; // 1
cout << mp['a'] << endl;       // 0
*/

/*
字符串
构造：string(长度，初值)

修改、查询指定下标字符      []        s[1] = 'a';
是否相同                   ==        if (s1 == s2) ...
字符串连接                  +        string s = s1 + s2
尾接字符串                  +=       s += "awa"
取子串                     .substr(起始下标, 子串长度)       string sub = s.substr(2, 10)
查找字符串                 .find(字符串, 起始下标)            int pos = s.find("awa");O(n^2)

数值与字符串互转（C++11）
| 源                                             | 目的        | 函数        |
| ---------------------------------------------- | ----------- | ----------- |
| int / long long / float / double / long double | string      | to_string() |
| string                                         | int         | stoi()      |
| string                                         | long long   | stoll()     |
| string                                         | float       | stof()      |
| string                                         | double      | stod()      |
| string                                         | long double | stold()     |

尾接字符串一定要用+=

string 的 += 运算符，将会在原字符串原地尾接字符串。而 + 了再 = 赋值，会先生成一个临时变量，在复制给 string.

通常字符串长度可以很长，如果使用 + 字符串很容易就 TLE 了。
// 优化前: 15139ms
string s;
for (int i = 0; i < 5e5; i++)
    s = s + "a";

// 优化后: < 1ms (计时器显示0)
string s;
for (int i = 0; i < 5e5; i++)
    s += "a";
*/

/*
二元组
构造：pair<第一个值类型, 第二个值类型> pr
赋值
老式
pair<int, char> pr = make_pair(1, 'a');

列表构造 C++11
pair<int, char> pr = {1, 'a'};

取值
直接取值
- 取第一个值：.first
- 取第二个值：.second

pair<int, char> pr = {1, 'a'};
int awa = pr.first;
char bwb = pr.second;

结构化绑定 C++17
pair<int, char> pr = {1, 'a'};
auto &[awa, bwb] = pr;

直接用==运算符
pair<int, int> p1 = {1, 2};
pair<int, int> p2 = {1, 3};
if (p1 == p2) { ... } // false
*/


/*
迭代器
for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
    cout << *it << endl;

a.begin()是一个迭代器，指向的是第一个元素
a.end()是一个迭代器，指向的是最后一个元素再后面一位
上述迭代器具有自增运算符，自增则迭代器向下一个元素移动
迭代器与指针相似，如果对它使用解引用运算符，即 *it，就能取到对应值了

很多数据结构并不是线性的（例如红黑树），对于非线性数据结构，下标是无意义的。无法使用下标来遍历整个数据结构。
迭代器的作用就是定义某个数据结构的遍历方式，通过迭代器的增减，代表遍历到的位置，通过迭代器便能成功遍历非线性结构了。
例如，set 的实现是红黑树，我们是没法用下标来访问元素的。但是通过迭代器，我们就能遍历 set 中的元素了：
for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
    cout << *it << endl;

对于 vector 容器，它的迭代器功能比较完整，以它举例：

.begin()：头迭代器
.end()：尾迭代器
.rbegin()：反向头迭代器
.rend()：反向尾迭代器
迭代器 `+` 整型：将迭代器向后移动
迭代器 `-` 整型：将迭代器向前移动
迭代器 `++`：将迭代器向后移动 1 位
迭代器 `--`：将迭代器向前移动 1 位
迭代器 `-` 迭代器：两个迭代器的距离
prev(it)：返回 it 的前一个迭代器
next(it)：返回 it 的后一个迭代器
对于其他容器，由于其结构特性，上面的功能不一定都有（例如 set 的迭代器是不能相减求距离的）

vector<int> a{1, 2, 3, 4};
for (auto it = a.begin(); it != a.end(); ++it)
    if (*it == 2 || *it == 3)
        a.erase(it);
// a = [1, 3, 4]，3没删除

vector<int> a{1, 2, 3, 4};
for (auto it = a.begin(); it != a.end(); ++it)
    if (*it == 4)
        a.erase(it);
//RE
*/

/*
常见算法
swap()
template< class T >
void swap( T& a, T& b );

int a = 0, b = 1;
swap(a, b);
// now a = 1, b = 0
int arr[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
swap(arr[4], arr[6]);
// now arr = {0, 1, 2, 3, 6, 5, 4, 7, 8, 9}


sort()
template< class RandomIt, class Compare >
void sort( RandomIt first, RandomIt last, Compare comp );

vector<int> arr{1, 9, 1, 9, 8, 1, 0};
sort(arr.begin(), arr.end());
// arr = [0, 1, 1, 1, 8, 9, 9]

vector<int> arr{1, 9, 1, 9, 8, 1, 0};
sort(arr.begin(), arr.end(), greater<int>());
// arr = [9, 9, 8, 1, 1, 1, 0]

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first > b.first;
}
int main()
{
    vector<pair<int, int>> arr{{1, 9}, {2, 9}, {8, 1}, {0, 0}};
	sort(arr.begin(), arr.end(), cmp);
    // arr = [(0, 0), (8, 1), (2, 9), (1, 9)]
}


lower_bound()/upper_bound()
函数	作用	返回迭代器指向
lower_bound(first, last, value)	查找第一个 >= value 的元素	第一个不小于 value 的位置
upper_bound(first, last, value)	查找第一个 > value 的元素	第一个大于 value 的位置

数组: [1, 2, 2, 2, 3, 4, 5]
索引:  0  1  2  3  4  5  6
查找 value = 2：
- lower_bound() → 返回索引 1（第一个 2）
- upper_bound() → 返回索引 4（第一个 >2 的元素，即 3 的位置）
查找 value = 6（不存在）：
- lower_bound() → 返回索引 7（end()）
- upper_bound() → 返回索引 7（end()）
查找 value = 0（不存在）：
- lower_bound() → 返回索引 0（第一个 >=0 的元素）
- upper_bound() → 返回索引 0（第一个 >0 的元素）

降序数组中的语义变化
函数	升序 (默认)	降序 (greater)
lower_bound	第一个 >= value	第一个 <= value
upper_bound	第一个 > value	第一个 < value
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = {9, 7, 5, 3, 1};  // 降序排列
    // 正确：传递 greater<int>() 作为比较函数
    auto it1 = lower_bound(v.begin(), v.end(), 5, greater<int>());
    cout << "lower_bound(5): 索引 " << (it1 - v.begin()) << ", 值 = " << *it1 << endl;
    // 输出: 索引 2, 值 = 5（第一个 <= 5 的元素）
    auto it2 = upper_bound(v.begin(), v.end(), 5, greater<int>());
    cout << "upper_bound(5): 索引 " << (it2 - v.begin()) << ", 值 = " << *it2 << endl;
    // 输出: 索引 3, 值 = 3（第一个 < 5 的元素）
    // 统计降序数组中 5 的个数
    auto left = lower_bound(v.begin(), v.end(), 5, greater<int>());
    auto right = upper_bound(v.begin(), v.end(), 5, greater<int>());
    cout << "数字 5 出现了 " << (right - left) << " 次" << endl;
    // 输出: 1 次
    return 0;


reverse()
反转一个可迭代对象的元素顺序
vector<int> arr(10);
iota(arr.begin(), arr.end(), 1);
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
reverse(arr.begin(), arr.end());
// 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
}


max()/min()
// Before C++11
int mx = max(max(1, 2), max(3, 4)); // 4
int mn = min(min(1, 2), min(3, 4)); // 1

// After C++11
int mx = max({1, 2, 3, 4}); // 4
int mn = min({1, 2, 3, 4}); // 1


unique()
消除数组的重复相邻元素，数组长度不变，但是有效数据缩短，返回的是有效数据位置的结尾迭代器。
单独使用 unique 并不能达成去重效果，因为它只消除**相邻**的重复元素。但是如果序列有序，那么它就能去重了。
vector<int> arr{1, 2, 1, 4, 5, 4, 4};
sort(arr.begin(), arr.end());
arr.erase(unique(arr.begin(), arr.end()), arr.end());


gcd()/lcm()
返回最大公因数 / 最小公倍数

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
*/