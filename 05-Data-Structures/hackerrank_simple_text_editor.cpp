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
    
    int q;
    if (!(cin >> q)) return 0;
    
    string s = "";
    stack<string> history;
    history.push(s);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            string w;
            cin >> w;
            s += w;
            history.push(s);
        } else if (type == 2) {
            int k;
            cin >> k;
            s.erase(s.size() - k);
            history.push(s);
        } else if (type == 3) {
            int k;
            cin >> k;
            cout << s[k - 1] << "\n";
        } else if (type == 4) {
            if (!history.empty()) {
                history.pop();
                s = history.top();
            }
        }
    }
    
    return 0;
}
