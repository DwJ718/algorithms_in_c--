#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    class UnionFind {
    private:
        vector<int> parent;
        vector<int> rank;
        int count;
        
    public:
        UnionFind(int n) : count(n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            
            if (rootX == rootY) return;
            
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
        
        int getCount() const {
            return count;
        }
    };
    
    // 验证函数：在限制边权为limit的情况下，能否使连通分量数量 ≤ k
    bool canAchieve(int n, const vector<vector<int>>& edges, int k, int limit) {
        UnionFind uf(n);
        
        for (const auto& edge : edges) {
            if (edge[2] <= limit) {
                uf.unite(edge[0], edge[1]);
            }
        }
        
        return uf.getCount() <= k;
    }
    
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        // 特殊情况：如果允许的连通分量数量 ≥ 节点数
        if (k >= n) return 0;
        
        // 收集所有边权并去重排序
        vector<int> weights;
        weights.push_back(0);  // 包含0作为候选答案
        for (const auto& edge : edges) {
            weights.push_back(edge[2]);
        }
        sort(weights.begin(), weights.end());
        weights.erase(unique(weights.begin(), weights.end()), weights.end());
        
        // 左开右开区间 (left, right)
        // left: 不满足条件的位置
        // right: 满足条件的位置
        int left = -1;  // 索引-1表示不满足（最小边权之前）
        int right = weights.size();  // 索引size()表示满足（最大边权之后）
        
        // 注意：right位置一定满足条件（最大边权一定可行）
        // 验证最大边权是否真的可行
        // 实际上，当limit = 最大边权时，所有边都被保留，连通分量数量最少
        // 因为 k < n，所以最大边权一定可行
        
        while (left + 1 < right) {  // 区间不为空
            int mid = left + (right - left) / 2;
            int limit = weights[mid];
            
            if (canAchieve(n, edges, k, limit)) {
                right = mid;  // 满足条件，缩小右边界
            } else {
                left = mid;   // 不满足条件，缩小左边界
            }
        }
        // 循环结束时，right是第一个满足条件的位置
        return weights[right];
    }
};
/*
学习并查集和图
*/