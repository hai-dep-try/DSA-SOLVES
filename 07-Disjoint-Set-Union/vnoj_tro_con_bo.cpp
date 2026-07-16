/*
    Platform: VNOJ
    Problem: Trò con bò - VNOJ Educational DSU
    Topic: DSU
    Complexity: O(K alpha(N))
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    vector<long long> val;//Luu gia tri dong gop cua nut nay voi cha cua no
    DSU (int n){
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        val.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if(parent[i] == i) return i;
        int p = parent[i];
        int root = find(p);

        if (p != root){
            val[i] += val[p];
        }
        parent[i] = root;
        return root;
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i == root_j) return;
        if (sz[root_i]> sz[root_j]) swap(root_i, root_j);
        
        parent[root_i] = root_j;
        val[root_i] -= val[root_j];
        sz[root_j] += sz[root_i];
        
    }
    void add(int i, long long v) {
        int root = find(i);
        val[root] += v;
    }
    long long get(int u) {
        long long sum = 0;
        while (true) {
            sum += val[u];
            if (u == parent[u]) break;
            u = parent[u];
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int n, k;
    if (!(cin >> n >> k)) return 0;
    DSU dsu(n);
    for (int i = 0; i < k; ++i) {
        string type;
        cin >> type;
        if (type == "join") {
            int u, v;
            cin >> u >> v;
            dsu.unite(u, v);
        } else if (type == "add") {
            int u;
            long long v;
            cin >> u >> v;
            dsu.add(u, v);
        } else if (type == "get") {
            int u;
            cin >> u;
            cout << dsu.get(u) << "\n";
        }
    }
    return 0;
}
