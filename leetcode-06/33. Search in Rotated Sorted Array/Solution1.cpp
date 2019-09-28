// Description:
// Suppose an array sorted in ascending order is rotated at some pivot
// unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search.
// If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1


// Binary Search:

#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid == hi, then lo == hi and
        // loop would have been terminated.
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        // lo == hi is the index of the smallest value and also the number of places rotated.
        int rot = lo;
        lo = 0;
        hi = nums.size() - 1;
        // The usual binary search and accounting for rotation.
        while (lo <= hi){
            int mid = (lo + hi) / 2;
            int realmid = (mid + rot) % nums.size();
            if (nums[realmid] == target) return realmid;
            if (nums[realmid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};