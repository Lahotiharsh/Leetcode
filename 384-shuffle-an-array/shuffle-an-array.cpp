class Solution {
public:
    vector<int> arr;
    int n;
    Solution(vector<int>& nums) {
        n = nums.size();
        for(int i = 0; i < n; i++) {
            arr.push_back(nums[i]);
        }      
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int> ans(arr.begin(), arr.end());
        for(int i = 0; i < n; i++) {
            swap(ans[i], ans[random() % n]);
        }
        return ans;
    }
};
