/*
    Platform: CSES (https://cses.fi/problemset/task/1629)
    Problem: Movie Festival
    Topic: Sort, Greedy
    Complexity: O(n log n) Time / O(n) Space
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 0;
    int current_end = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].first >= current_end) {
            count++;
            current_end = movies[i].second;
        }
    }

    cout << count << "\n";
    return 0;
}
