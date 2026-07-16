/*
    Platform: VNOJ
    Problem: Mọi người đang rời đi - VNOJ Educational DSU
    Topic: DSU
    Complexity: O(M alpha(N))
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 2);
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
    
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        char type;
        int x;
        cin >> type >> x;
        if (type == '-') {
            int root_x = dsu.find(x);
            int root_next = dsu.find(x + 1);
            if (root_x != root_next) {
                dsu.parent[root_x] = root_next;
            }
        } else if (type == '?') {
            int ans = dsu.find(x);
            if (ans > n) {
                cout << -1 << "\n";
            } else {
                cout << ans << "\n";
            }
        }
    }
    
    return 0;
}
