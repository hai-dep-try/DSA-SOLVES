/*
    Platform: VNOJ (https://oj.vnoi.info/problem/colquery)
    Problem: Color query
    Topic: DSU + Small to Large
    Complexity: O(Q * log^2(N))
    Date: 2026-07-14
*/

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<map<int, int>> color_cnt;

    DSU(int n, const vector<int>& a) {
        parent.resize(n + 1);
        color_cnt.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        for (int i = 1; i <= n; ++i) {
            color_cnt[i][a[i]] = 1;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    bool unite_sets(int u, int v) {
        int root_u = find_set(u);
        int root_v = find_set(v);
        if (root_u != root_v) {
            if (color_cnt[root_u].size() < color_cnt[root_v].size()) {
                swap(root_u, root_v);
            }
            parent[root_v] = root_u;
            for (auto const& [col, cnt] : color_cnt[root_v]) {
                color_cnt[root_u][col] += cnt;
            }
            color_cnt[root_v].clear();
            return true;
        }
        return false;
    }

    int query(int u, int c) {
        int root = find_set(u);
        if (color_cnt[root].find(c) != color_cnt[root].end()) {
            return color_cnt[root][c];
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    DSU dsu(n, a);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            dsu.unite_sets(u, v);
        } else if (type == 2) {
            int u, c;
            cin >> u >> c;
            cout << dsu.query(u, c) << "\n";
        }
    }

    return 0;
}
