// OJ: https://leetcode.com/problems/single-number-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int bit = 0;
            for (int n : nums) {
                bit += (n >> i) & 1;
                if (bit >= 3) bit = 0;
            }
            ans |= bit << i;
        }
        return ans;
    }
};