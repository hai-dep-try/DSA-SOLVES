# Cấu trúc dữ liệu các tập hợp rời nhau (Disjoint Set Union - DSU)

Cấu trúc dữ liệu các tập hợp rời nhau (DSU hoặc Union-Find) được sử dụng để quản lý một tập hợp các phần tử được chia thành nhiều tập con không giao nhau. DSU hỗ trợ 2 thao tác chính một cách cực kỳ hiệu quả:
1. **Find**: Tìm đại diện (root) của tập hợp chứa phần tử $u$.
2. **Union**: Gộp hai tập hợp chứa phần tử $u$ và $v$ lại với nhau.

## Các kỹ thuật tối ưu hóa chính
Để đạt độ phức tạp gần như hằng số $O(\alpha(N))$ (với $\alpha$ là hàm ngược Ackermann, thực tế nhỏ hơn 5), ta áp dụng 2 kỹ thuật:
- **Path Compression (Nén đường đi)**: Khi tìm kiếm root của $u$, gán trực tiếp cha của tất cả các phần tử trên đường đi tới root là chính root đó.
- **Union by Size/Rank (Gộp theo kích thước/độ cao)**: Gộp tập hợp nhỏ hơn vào tập hợp lớn hơn để tránh cây bị suy biến thành danh sách liên kết.

## Template DSU cơ bản (C++)

```cpp
struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]); // Path compression
    }
    
    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v); // Union by size
        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
};
```

## Các bài tập đáng chú ý trong thư mục này
- **[leetcode_547_number_of_provinces.cpp](file:///f:/Baitapc++/DSA-Solves/07-Disjoint-Set-Union/leetcode_547_number_of_provinces.cpp)**: Bài toán đếm số lượng thành phần liên thông cơ bản.
- **[codeforces_1167c_news_distribution.cpp](file:///f:/Baitapc++/DSA-Solves/07-Disjoint-Set-Union/codeforces_1167c_news_distribution.cpp)**: Quản lý kích thước của từng thành phần liên thông (truy vấn size của root).
- **[vnoj_monkeys.cpp](file:///f:/Baitapc++/DSA-Solves/07-Disjoint-Set-Union/vnoj_monkeys.cpp)**: Kỹ thuật xử lý ngược (Offline query) - duyệt từ cuối về đầu để chuyển bài toán hủy liên kết thành gộp liên kết.
- **[vnoj_colquery.cpp](file:///f:/Baitapc++/DSA-Solves/07-Disjoint-Set-Union/vnoj_colquery.cpp)**: Kết hợp DSU và cấu trúc map để đếm số lượng phần tử có cùng màu sắc khi gộp tập hợp (áp dụng kỹ thuật gộp nhỏ vào lớn - Small to Large).
