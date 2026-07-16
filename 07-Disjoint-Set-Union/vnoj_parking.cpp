#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u){
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int n;
    if(!(cin >> n)) return 0;
    
    DSU dsu(n);
    for (int i = 0; i < n; i++){
        int p;
        cin >> p;
        int pos = dsu.find(p);
        cout << pos << (i == n - 1 ? "" : " ");
        int nxt = pos % n + 1;
        dsu.parent[pos] = dsu.find(nxt);
    }
    cout <<"\n";
    return 0;
}