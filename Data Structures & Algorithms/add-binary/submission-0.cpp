class Solution {
public:
    string addBinary(string a, string b) {
            int i = a.size() -1, j = b.size() - 1;
            int carry = 0;
            string result;

            while (i >= 0 || j >= 0 || carry)
            {
                int bit_a = (i >= 0) ? a[i] - '0' : 0;
                int bit_b = (j >= 0) ? b[j] - '0' : 0;
                
                int total = carry + bit_a + bit_b;
                result.push_back('0' + (total % 2));
                carry = total / 2;

                i--;
                j--;
            }
            reverse(result.begin(), result.end());
            return result;
    }
};