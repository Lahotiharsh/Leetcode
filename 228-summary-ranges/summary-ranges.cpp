class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int next=0;
        for(int i=next;i<(nums.size());i++){
            if(i==(nums.size()-1)||nums[i+1]!=nums[i]+1){
                if(next==i){
                    ans.push_back(to_string(nums[next]));
                }
                else{
                ans.push_back(to_string(nums[next]) + "->" + to_string(nums[i]));
                }
                next=i+1;
            }
        }
        return ans;
    }
};