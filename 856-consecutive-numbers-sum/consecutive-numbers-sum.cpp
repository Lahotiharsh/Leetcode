class Solution {
public:
    int consecutiveNumbersSum(int n) {
        if (n == 1) return 1;
        int count = 1;
        int var = 2; 
        while (true){
            int calc = (n - ((var-1)*var/2)) / var;
            
            if ((n - ((var-1)*var/2)) % var == 0){  
                count++;
            }
            var++;
            calc = (n - ((var-1)*var/2)) / var;   
            if (calc == 0) break;
        }
        return count;
    }
};