class Solution {
public:
    string toHex(int num) {
        if (!num) return "0";
        unsigned int ourNum = num;

        string res;
        string hex = "0123456789abcdef";

        while (ourNum) {
            res += hex[ourNum % 16];
            ourNum /= 16;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};