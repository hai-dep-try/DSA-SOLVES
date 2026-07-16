/*
    Platform: VNOJ
    Problem: Cutting a graph - VNOJ Educational DSU
    Topic: DSU
    Complexity: O((N + M + K) alpha(N))
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
    }
    
    vector<pair<string, pair<int, int>>> queries(k);
    for (int i = 0; i < k; ++i) {
        cin >> queries[i].first >> queries[i].second.first >> queries[i].second.second;
    }
    
    DSU dsu(n);
    vector<string> ans;
    for (int i = k - 1; i >= 0; --i) {
        if (queries[i].first == "cut") {
            dsu.unite(queries[i].second.first, queries[i].second.second);
        } else {
            if (dsu.find(queries[i].second.first) == dsu.find(queries[i].second.second)) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    for (const string& s : ans) {
        cout << s << "\n";
    }
    
    return 0;
}
