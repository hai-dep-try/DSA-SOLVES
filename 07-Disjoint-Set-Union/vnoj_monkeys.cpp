/*
    Platform: VNOJ
    Problem: Monkeys - VNOJ Educational DSU
    Topic: DSU
    Complexity: O((N + M) alpha(N))
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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> left_hand(n + 1, -1);
    vector<int> right_hand(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        cin >> left_hand[i] >> right_hand[i];
    }

    vector<pair<int, int>> events(m);
    vector<vector<bool>> dropped(n + 1, vector<bool>(2, false));
    for (int i = 0; i < m; ++i) {
        cin >> events[i].first >> events[i].second;
        dropped[events[i].first][events[i].second - 1] = true;
    }

    DSU dsu(n);
    vector<int> fall_time(n + 1, -1);
    vector<vector<int>> comp(n + 1);
    for(int i = 1; i <= n; ++i) {
        comp[i].push_back(i);
    }
    
    auto unite = [&](int u, int v, int t) {
        if (u == -1 || v == -1) return;
        int root_u = dsu.find(u);
        int root_v = dsu.find(v);
        if (root_u != root_v) {
            int root1 = dsu.find(1);
            bool u_has_1 = (root_u == root1);
            bool v_has_1 = (root_v == root1);
            
            if (comp[root_u].size() < comp[root_v].size()) {
                swap(root_u, root_v);
                swap(u_has_1, v_has_1);
            }
            dsu.parent[root_v] = root_u;
            
            if (u_has_1 && !v_has_1) {
                for (int x : comp[root_v]) fall_time[x] = t;
            } else if (!u_has_1 && v_has_1) {
                for (int x : comp[root_u]) fall_time[x] = t;
            }
            
            for (int x : comp[root_v]) {
                comp[root_u].push_back(x);
            }
            comp[root_v].clear();
            comp[root_v].shrink_to_fit();
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (!dropped[i][0] && left_hand[i] != -1) unite(i, left_hand[i], -1);
        if (!dropped[i][1] && right_hand[i] != -1) unite(i, right_hand[i], -1);
    }

    for (int i = m - 1; i >= 0; --i) {
        int u = events[i].first;
        int hand = events[i].second;
        int v = (hand == 1) ? left_hand[u] : right_hand[u];
        unite(u, v, i);
    }

    for (int i = 1; i <= n; ++i) {
        cout << fall_time[i] << "\n";
    }
    return 0;
}
