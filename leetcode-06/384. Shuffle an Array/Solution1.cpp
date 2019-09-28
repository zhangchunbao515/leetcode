// Description:
// Shuffle a set of numbers without duplicates.

// Example:
// Init an array with set 1, 2, and 3.
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
// solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
// solution.reset();

// Returns the random shuffling of array [1,2,3].
// solution.shuffle();

#include<vector>
using namespace std;

class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        srand((unsigned)time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(nums);
        for (int i = 0; i < res.size(); ++i) {
            swap(res[i], res[rand() % res.size()]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
