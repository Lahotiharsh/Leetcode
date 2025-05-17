class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0);
        long long mini=*min_element(nums.begin(),nums.end());
        int n=nums.size();
        return sum-n*mini;
    }
};