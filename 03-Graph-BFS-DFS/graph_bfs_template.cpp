#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int par[MAXN];
unordered_map<int, int> color_count[MAXN];

int find_set(int u) {
    if (par[u] == u) 
        return u;
    return par[u] = find_set(par[u]);
}

void union_sets(int u, int v){
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u != root_v){
        if (color_count[root_u].size() < color_count[root_v].size()){
            swap(root_u, root_v);
        }
        par[root_v] = root_u;
        for (auto& p: color_count[root_v]){
            color_count[root_u][p.first] += p.second;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        int c;
        cin >> c;
        color_count[i][c] = 1;
    }
    for (int i = 1; i <= q; i++){
        int type;
        cin >> type;
        
        if (type == 1){
            int u, v;
            cin >> u >> v;
            union_sets(u, v);
        }
        else if (type == 2){
            int u, c;
            cin >> u >> c;

            int root_u = find_set(u);
            if (color_count[root_u].count(c)){
                cout << color_count[root_u][c] << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
   
    return 0;
}