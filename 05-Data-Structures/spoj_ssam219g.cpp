#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    h.push_back(0);
    stack<int> st;
    long long max_area = 0;
    // Bước 1: Tìm L[i] - Cột đầu tiên bên trái thấp hơn h[i]
    for (int i = 0; i < n + 1; i++) {
        while (!st.empty() && h[st.top()] >= h[i]){
            int top_idx = st.top();
            st.pop();

            long long w;
            if (st.empty()){
                w = i;
            } else {
                w = i - st.top() - 1;
            }
            max_area = max(max_area, h[top_idx]*w);
        }
        st.push(i);
    }

    // Bước 3: Tính diện tích lớn nhất
    

    cout << max_area << "\n";
}

int main() {
    // Tối ưu tốc độ nhập xuất dữ liệu trong C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}