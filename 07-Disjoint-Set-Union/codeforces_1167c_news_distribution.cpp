/*
    Platform: Codeforces
    Problem: 1167C - News Distribution
    Topic: DSU
    Complexity: O((N + sum(K)) alpha(N))
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
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        int first_person = -1;
        for (int j = 0; j < k; ++j) {
            int person;
            cin >> person;
            if (first_person == -1) {
                first_person = person;
            } else {
                dsu.unite(first_person, person);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << dsu.sz[dsu.find(i)] << (i == n ? "" : " ");
    }
    cout << "\n";
    return 0;
}
