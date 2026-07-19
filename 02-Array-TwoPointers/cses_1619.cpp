#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arrive(n);
    vector<int> leave(n);
    for (int i = 0; i < n; i++) {
        cin >> arrive[i] >> leave[i];
    }
    sort(arrive.begin(), arrive.end());
    sort(leave.begin(), leave.end());
    int i = 0, j = 0;
    int cur = 0, ans = 0;
    while (i < n && j < n){
        if (arrive[i] < leave[j]){
            cur++;
            i++;
        } else {
            cur--;
            j++;
        }
        ans = max(ans, cur);
    }

    cout << ans << "\n";
    return 0;
}
