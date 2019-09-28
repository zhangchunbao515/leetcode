// OJ: https://leetcode.com/problems/house-robber/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int doRob = 0, doNotRob = 0;
        for (int n : nums) {
            int tmp = doNotRob;
            doNotRob = max(doRob, doNotRob);
            doRob = tmp + n;
        }
        return max(doRob, doNotRob);
    }
};