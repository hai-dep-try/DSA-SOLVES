/*
    Platform: VNOJ
    Problem: Giá trị tập - VNOJ Educational DSU
    Topic: DSU
    Complexity: O(M alpha(N))
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, mn, mx, sz;
    DSU(int n) {
        parent.resize(n + 1);
        mn.resize(n + 1);
        mx.resize(n + 1);
        sz.resize(n + 1, 1); //Khoi tao tat ca size = 1
        for(int i=1; i<=n; ++i) {
            parent[i] = i; // moi phan tu la goc cua chinh no
            mn[i] = mx[i] = i; //min va max ban dau cua moi ptu la chinh no
        }
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);//Nen duong di
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i == root_j) return; // cung nhom thi bo qua

        //Neu cay cua root_i to hon root_j, doi cho de root_j luon to hon
        if (sz[root_j] < sz[root_i]){
            swap(root_i, root_j);
        }

         //Neu khong cung 1 nhom
        parent[root_i] = root_j; //gop cay
        mn[root_j] = min(mn[root_j], mn[root_i]); //min thi lay gia tri cay nho hon
        mx[root_j] = max(mx[root_j], mx[root_i]); //max thi lay gia tri cay to hon
        sz[root_j] += sz[root_i];
        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        string type;
        cin >> type;
        if (type == "union") {
            int u, v;
            cin >> u >> v;
            dsu.unite(u, v);
        } else if (type == "get") {
            int u;
            cin >> u;
            int r = dsu.find(u);
            cout << dsu.mn[r] << " " << dsu.mx[r] << " " << dsu.sz[r] << "\n";
        }
    }
    return 0;
}
