class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        int mini = INT_MAX;

        vector<int> minutes;
        for(auto& val:tp){ // int i=0;i<v.size();i++

            int hr = 10 * (val[0] - '0') + (val[1] - '0'); // 2*10 + 3 = 23
            // val[2] = :
            int min = 10 * (val[3] - '0') + (val[4] - '0'); // 5*10 + 9 = 59

            // convert whole to minute starting point -> 00            
            minutes.push_back(hr * 60 + min);
        }

        // Sort the minutes
        sort(minutes.begin(), minutes.end());

        // Calculate the minimum difference between adjacent times
        for(int i = 1; i < minutes.size(); i++){
            mini = min(mini, minutes[i] - minutes[i-1]);
        }

        // Also, check the difference between the first and last time, considering the 24-hour wraparound
        int n = minutes.size();
        mini = min(mini, 1440 - (minutes[n-1] - minutes[0]));

        return mini;
    }
};