class Solution {
public:
    string originalDigits(string s) {
        
        int nums[10];
        vector<int> freq(26);
        for(int i =0 ;i< s.size();i++){
            freq[s[i]-'a']+=1;
        }
        nums[0] = freq['z' - 'a'];
        nums[2] = freq['w' - 'a']; 
        nums[4] = freq['u' - 'a']; 
        nums[5] = freq['f' - 'a'] - nums[4];
        nums[6] = freq['x' - 'a']; 
        nums[8] = freq['g' - 'a']; 
        nums[1] = freq['o' - 'a'] - nums[0] - nums[2] - nums[4]; 
        nums[3] = freq['h' - 'a'] - nums[8];
        nums[7] = freq['s' - 'a'] - nums[6];
        nums[9] = freq['i' - 'a'] - nums[6] - nums[8] - nums[5]; 

        string result = "";
        for (int i = 0; i < 10; i++) {
            if (nums[i] != 0) {
                result += string(nums[i], '0' + i);
            }
        }
        return result;
    }
};