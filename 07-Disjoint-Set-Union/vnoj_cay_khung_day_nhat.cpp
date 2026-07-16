#include <bits/stdc++.h>
using namespace std;

// Cấu trúc lưu cạnh
struct Edge {
    int u, v;
    long long w;
};

// Hàm so sánh để sắp xếp cạnh tăng dần theo trọng số
bool compareEdge(Edge a, Edge b) {
    return a.w < b.w;
}

// Cấu trúc DSU tối giản nhất
struct DSU {
    vector<int> parent, sz;
    
    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void reset(int n) {
        iota(parent.begin(), parent.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i == root_j) return false; // Trùng gốc, không gộp được
        if (sz[root_i] > sz[root_j]) swap(root_i, root_j);
        parent[root_i] = root_j; // Gộp
        sz[root_j] += sz[root_i];
        return true;
    }
};

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sắp xếp các cạnh tăng dần
    sort(edges.begin(), edges.end(), compareEdge);

    long long min_diff = -1;
    DSU dsu(n);
    // Xét từng cạnh i làm cạnh nhỏ nhất
    for (int i = 0; i < m; ++i) {
        if (m - i < n - 1) break;

        dsu.reset(n); // Khởi tạo lại DSU mới tinh cho mỗi vòng lặp
        int edges_added = 0; // Đếm số cạnh đã ghép thành công vào cây

        // Lấy các cạnh từ i trở đi để thử ghép
        for (int j = i; j < m; ++j) {
            if (dsu.unite(edges[j].u, edges[j].v) == true) {
                edges_added++; 
            }

            // Cây khung luôn có đúng n - 1 cạnh
            if (edges_added == n - 1) {
                long long diff = edges[j].w - edges[i].w;
                if (min_diff == -1 || diff < min_diff) {
                    min_diff = diff;
                }
                break; // Xong cây khung cho vòng lặp i, thoát ra xét i tiếp theo
            }
        }
    }

    if (min_diff == -1) cout << "NOT FOUND\n";
    else cout << min_diff << "\n";

    return 0;
}