
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

long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    
    DSU dsu(n);
    for (int i = 0; i < n - 1; ++i){
        char type;
        int u, v;
        cin >> u >> v >> type;
        if (type == 'b'){
            dsu.unite(u, v);
        }

    }
    long long total = n * (n - 1) * (n - 2);
    
    
    return 0;
}
