// Description:
// A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative.
// The first difference (if one exists) may be either positive or negative.
// A sequence with fewer than two elements is trivially a wiggle sequence.

// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative.
// In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences,
// the first because its first two differences are positive and the second because its last difference is zero.

// Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence.
// A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence,
// leaving the remaining elements in their original order.

// Example 1:
// Input: [1,7,4,9,2,5]
// Output: 6

// Example 2:
// Input: [1,17,5,10,13,15,10,5,16,8]
// Output: 7

// Example 3:
// Input: [1,2,3,4,5,6,7,8,9]
// Output: 2

// Follow up:
// Can you do it in O(n) time?

// Greedy solution:
// Time Complexity: O(n), Space Complexity: O(1)

#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        // prev_diff:
        // indicate whether the current subsequence of numbers lies in an increasing or decreasing wiggle.
        int prev_diff = 0; 
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int diff = nums[i] - nums[i-1];
            // if prev_diff > 0
            // update the length of the found subsequence when diff becomes negative.
            // if prev_diff < 0
            // update the length of the found subsequence when diff becomes positive.  
            if((diff > 0 && prev_diff<= 0) || (diff < 0 && prev_diff >= 0)) {
                ++res;
                prev_diff = diff;
            }
        }
        return res;
    }
};