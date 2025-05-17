class Solution {
public:
    int numTrees(int n) {
        int result=0;
        if(n==1 || n==0)
            return 1;
        for(int i=0;i<n;i++)
            result+=numTrees(i)*numTrees(n-i-1);
        return result;
    }
};