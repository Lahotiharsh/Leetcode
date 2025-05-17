class Solution { 
private:
    int backtrack(vector<bool>& chosen, int k, int n) {
        
        if (k < 1)
            return 1;

        int numUnique = 0;

        for (int j = 0; j <= 9; ++j)
        {
            if ((chosen[j] == false) && (j != 0 || k != n))
            {
                chosen[j] = true;
                numUnique += backtrack(chosen, k - 1, n);
                chosen[j] = false;
            }
        }

        return numUnique;
    }

public:
    int countNumbersWithUniqueDigits(int n) {
        
        int count = 0;
        vector<bool> chosen(10, false);

        for (int i = 0; i <= n; ++i)
            count += backtrack(chosen, i, i);

        return count;
    }
};