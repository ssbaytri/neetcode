class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int target = 0; target < n + 1; target++)
        {
            int count = 0;
            int x = target;

            while (x) {
                count += x & 1;
                x >>= 1;
            }
            res.push_back(count);
        }
        return res;
    }
};
