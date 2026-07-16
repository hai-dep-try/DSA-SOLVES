/*
    Platform: HackerRank
    Problem: Queue using Two Stacks
    Topic: Stack/Queue
    Complexity: Amortized O(1) Time / O(N) Space
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    if (!(cin >> q)) return 0;
    
    stack<int> s1, s2;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            s1.push(x);
        } else if (type == 2) {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if (!s2.empty()) s2.pop();
        } else if (type == 3) {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if (!s2.empty()) cout << s2.top() << "\n";
        }
    }
    
    return 0;
}
