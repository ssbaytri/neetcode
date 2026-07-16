class Solution {
public:
    int reverse(int x) {
        long res = 0;
        int digit;

        while (x != 0)
        {
            digit = x % 10;
            x /= 10;
            res = res * 10 + digit;
        }

        if (res < INT_MIN || res > INT_MAX)
            return 0;
        
        return (int)res;
    }
};
