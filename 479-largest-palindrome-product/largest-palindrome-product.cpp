class Solution 
{
public:
    int largestPalindrome(int n) 
    {
        if(n==1) return 9;
        long long l=pow(10,n-1), r=pow(10,n)-1;
        for(long long x=r; x>=l; x--)
        {
            string s=to_string(x);
            string rev=s;
            reverse(rev.begin(),rev.end());
            s=s+rev;
            long long palin=stoll(s);
            for(long long y=r; y*y>=palin; y--)
            {
                if(palin/y>r) break;
                if(palin%y==0) return (int)(palin%1337);
            }
        }
        return -1;
    }
};