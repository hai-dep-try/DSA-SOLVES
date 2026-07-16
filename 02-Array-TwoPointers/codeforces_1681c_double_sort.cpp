/*
    Platform: Codeforces (https://codeforces.com/problemset/problem/1681/C)
    Problem: Double Sort
    Topic: Sort
    Complexity: O(t * n^2) Time / O(n) Space
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> swaps;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1] || (a[j] == a[j + 1] && b[j] > b[j + 1])) {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                swaps.push_back({j + 1, j + 2});
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        if (b[i] > b[i + 1]) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << -1 << "\n";
    } else {
        cout << swaps.size() << "\n";
        for (auto p : swaps) {
            cout << p.first << " " << p.second << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
