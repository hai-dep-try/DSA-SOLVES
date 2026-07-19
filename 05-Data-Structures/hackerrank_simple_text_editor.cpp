/*
    Platform: HackerRank
    Problem: Simple Text Editor
    Topic: Stack/Queue
    Complexity: O(Q) Time / O(Q * |S|) Space
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    int q;
    if (!(cin >> q)) return 0;
    
    string s = "";
    stack<pair<int, string>> history;
    
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            string w;
            cin >> w;
            s += w;
            history.push({1, w});
        } else if (type == 2) {
            int k;
            cin >> k;
            string w = s.substr(s.size() - k);
            history.push({2, w});
            s.erase(s.size() - k);
            
        } else if (type == 3) {
            int k;
            cin >> k;
            cout << s[k - 1] << "\n";
        } else if (type == 4) {
            if (!history.empty()) {
                auto [t, val] = history.top();
                history.pop();
                if (t == 1) {
                    s.erase(s.size() - val.size());
                } else if (t == 2) {
                    s += val;
                }
            }
        }
    }
    
    return 0;
}
