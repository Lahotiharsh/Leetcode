#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, current, nums, result);
        return result;
    }

    void backtrack(int index, vector<int>& current, vector<int>& nums, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        backtrack(index + 1, current, nums, result); 
        current.push_back(nums[index]);
        backtrack(index + 1, current, nums, result); 
        current.pop_back();     }
};