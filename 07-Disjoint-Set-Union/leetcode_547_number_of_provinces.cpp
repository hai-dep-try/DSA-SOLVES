/*
    Platform: LeetCode
    Problem: 547. Number of Provinces
    Topic: DSU
    Complexity: O(N^2 alpha(N))
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct DSU {
        vector<int> parent;
        int count;
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            count = n;
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        void unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
                count--;
            }
        }
    };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if (isConnected[i][j]) {
                    dsu.unite(i, j);
                }
            }
        }
        return dsu.count;
    }
};
