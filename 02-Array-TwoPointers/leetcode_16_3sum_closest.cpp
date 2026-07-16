/*
    Platform: LeetCode
    Problem: 3Sum Closest
    Topic: Sort, Two Pointers
    Complexity: O(n^2) Time / O(1) Space
    Date: 2026-07-14
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, target;
    if (!(cin >> n >> target)) return 0;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (n < 3) return 0;

    sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];
            if (abs(target - current_sum) < abs(target - closest)) {
                closest = current_sum;
            }
            if (current_sum > target) {
                right--;
            } else if (current_sum < target) {
                left++;
            } else {
                cout << closest << "\n";
                return 0;
            }
        }
    }
    
    cout << closest << "\n";
    return 0;
}
