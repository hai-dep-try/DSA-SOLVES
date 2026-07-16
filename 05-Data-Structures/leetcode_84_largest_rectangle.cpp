/*
    Platform: LeetCode
    Problem: 84. Largest Rectangle in Histogram
    Topic: Stack/Queue
    Complexity: O(N) Time / O(N) Space
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

long long largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    long long max_area = 0;
    
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && h < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, 1LL * height * width);
        }
        st.push(i);
    }
    
    return max_area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        cout << largestRectangleArea(heights) << "\n";
    }
    
    return 0;
}
