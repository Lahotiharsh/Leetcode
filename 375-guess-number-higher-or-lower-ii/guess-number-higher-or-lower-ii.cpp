class Solution {
public:
    int memo(int start, int end, vector<vector<int>>& dp) {
        if (start >= end) return 0; // Base case
        if (dp[start][end] != -1) return dp[start][end]; // Use cached result

        int ans = INT_MAX;
        for (int i = start; i <= end; ++i) { 
            ans = min(ans, i + max(memo(start, i - 1, dp), memo(i + 1, end, dp)));
        }

        return dp[start][end] = ans; // Store result
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return memo(1, n, dp);
    }
};