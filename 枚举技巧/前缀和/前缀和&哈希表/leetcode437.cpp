#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        // key：从根到 node 的节点值之和
        // value：节点值之和的出现次数
        // 注意在递归过程中，哈希表只保存根到 node 的路径的前缀的节点值之和
        unordered_map<long long, int> cnt = {{0, 1}};
        int ans = 0;

        // lambda 递归
        // s 表示从根到 node 的父节点的节点值之和（node 的节点值尚未计入）
        auto dfs = [&](this auto& dfs, TreeNode* node, long long s) {//写 this：对象参数，代表 lambda 自身，调用时自动绑定。优先写this
            if (node == nullptr) {
                return;
            }

            s += node->val;
            // 把 node 当作路径的终点，统计有多少个起点
            ans += cnt[s - targetSum]; // 注意这样写会把 s-targetSum 插入哈希表，介意的话可以特判

            cnt[s]++;//s - targetSum == s也就是targetsum为0时会影响答案，要先更新ans再cnt
            dfs(node->left, s);
            dfs(node->right, s);
            cnt[s]--; // 撤销 cnt[s]++（恢复现场）
        };

        dfs(root, 0);
        return ans;
    }
};
*/