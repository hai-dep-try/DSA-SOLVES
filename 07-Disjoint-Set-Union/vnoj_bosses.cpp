/*
    Platform: VNOJ
    Problem: Bosses - VNOJ Educational DSU
    Topic: DSU
    Complexity: O(M alpha(N))
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> dist;
    DSU(int n) {
        parent.resize(n + 1);
        dist.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        int p = parent[i];
        int root = find(p);
        dist[i] += dist[p];
        parent[i] = root;
        return root;
    }
    void unite(int i, int j) {
        parent[i] = j;
        dist[i] = 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            dsu.unite(u, v);
        } else if (type == 2) {
            int u;
            cin >> u;
            dsu.find(u);
            cout << dsu.dist[u] << "\n";
        }
    }
    
    return 0;
}
