#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minimumDistanceQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices_of;
        
        // Lưu trữ các vị trí của từng giá trị trong mảng
        for (int i = 0; i < n; ++i) {
            indices_of[nums[i]].push_back(i);
        }
        
        // Tính toán trước khoảng cách nhỏ nhất cho mọi vị trí
        vector<int> min_dist(n, -1);
        for (auto& pair : indices_of) {
            const vector<int>& pos = pair.second;
            int k = pos.size();
            
            // Nếu có từ 2 phần tử giống nhau trở lên thì tính khoảng cách
            if (k > 1) {
                for (int j = 0; j < k; ++j) {
                    // Lấy vị trí ngay liền kề trái và phải trong mảng vòng
                    int left_idx = pos[(j - 1 + k) % k];
                    int right_idx = pos[(j + 1) % k];
                    
                    // Khoảng cách trong mảng vòng = min(|a - b|, n - |a - b|)
                    int d1 = min(abs(pos[j] - left_idx), n - abs(pos[j] - left_idx));
                    int d2 = min(abs(pos[j] - right_idx), n - abs(pos[j] - right_idx));
                    
                    min_dist[pos[j]] = min(d1, d2);
                }
            }
        }
        
        // Trả lời các truy vấn
        vector<int> answer;
        answer.reserve(queries.size());
        for (int q : queries) {
            answer.push_back(min_dist[q]);
        }
        
        return answer;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 3, 1, 4, 1, 3, 2};
    vector<int> queries1 = {0, 3, 5};
    vector<int> ans1 = sol.minimumDistanceQueries(nums1, queries1);
    
    cout << "Example 1 Output: [";
    for (size_t i = 0; i < ans1.size(); ++i) {
        cout << ans1[i] << (i < ans1.size() - 1 ? "," : "");
    }
    cout << "]\n"; // Expected: [2,-1,3]

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> queries2 = {0, 1, 2, 3};
    vector<int> ans2 = sol.minimumDistanceQueries(nums2, queries2);
    
    cout << "Example 2 Output: [";
    for (size_t i = 0; i < ans2.size(); ++i) {
        cout << ans2[i] << (i < ans2.size() - 1 ? "," : "");
    }
    cout << "]\n"; // Expected: [-1,-1,-1,-1]

    return 0;
}
