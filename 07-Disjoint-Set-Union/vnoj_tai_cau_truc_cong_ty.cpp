/*
    Platform: VNOJ
    Problem: Tái cấu trúc công ty - VNOJ Educational DSU
    Topic: DSU
    Complexity: O((N + Q) alpha(N))
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
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
        }
    }
};

struct DSU_nxt {
    vector<int> parent;
    DSU_nxt(int n) {
        parent.resize(n + 1);
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
            parent[min(root_i, root_j)] = max(root_i, root_j);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    DSU dsu(n);
    DSU_nxt nxt(n + 1);
    
    for (int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            dsu.unite(u, v);
        } else if (type == 2) {
            int curr = nxt.find(u);
            while (curr < v) {
                dsu.unite(curr, curr + 1);
                nxt.unite(curr, curr + 1);
                curr = nxt.find(curr);
            }
        } else if (type == 3) {
            if (dsu.find(u) == dsu.find(v)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}
