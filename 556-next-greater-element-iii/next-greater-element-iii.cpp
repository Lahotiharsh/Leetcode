class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        if(!next_permutation(num.begin(),num.end()))  return -1;
        
        // to convert the string to long long integer
        long long res = stoll(num);
        return (res> INT_MAX) ? -1: res;

    }
};