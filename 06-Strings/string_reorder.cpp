#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm giải quyết cho từng Test Case
void solve() {
    int n, a;
    cin >> n >> a;
    vector<long long> v(n);
    for (int i = 1; i < n; i++) {
        cin >> v[i];
    }
    auto it = lower_bound(v.begin(), v.end(), a);
    int count_less = (int)distance(v.begin(), it);

    auto it_upper = upper_bound(v.begin(), v.end(), a);
    int count_greater = n - (int)distance(v.begin(), it_upper);

    if (count_greater > count_less) {
        cout << a + 1 << endl;
    } else cout << a - 1 << endl;

}

int main() {
    // Tăng tốc độ đọc ghi (Fast I/O) - Quan trọng với bài này vì T lên tới 1000
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}