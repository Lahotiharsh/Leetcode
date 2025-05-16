class Solution {
public:
    int kthSmallest(vector<vector<int>>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size();i++){
            for(int j = 0; j < nums[0].size();j++){
                pq.push(nums[i][j]);
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        return pq.top();
        
    }
};