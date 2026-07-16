/*
    Platform: HackerRank
    Problem: Merging Communities
    Topic: DSU
    Complexity: O(Q alpha(N))
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> sz;
    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
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
            sz[root_j] += sz[root_i];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    DSU dsu(n);
    for (int i = 0; i < q; ++i) {
        char type;
        cin >> type;
        if (type == 'M') {
            int u, v;
            cin >> u >> v;
            dsu.unite(u, v);
        } else if (type == 'Q') {
            int u;
            cin >> u;
            cout << dsu.sz[dsu.find(u)] << "\n";
        }
    }
    
    return 0;
}
