// Description:
// Write a program to find the n-th ugly number.
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

// Note:  
// 1 is typically treated as an ugly number.
// n does not exceed 1690.


// (1) 1×2, 2×2, 3×2, 4×2, 5×2, …
// (2) 1×3, 2×3, 3×3, 4×3, 5×3, …
// (3) 1×5, 2×5, 3×5, 4×5, 5×5, …
// Every subsequence is the ugly-sequence itself (1, 2, 3, 4, 5, …) multiply 2, 3, 5.
// Use similar merge method as merge sort, to get every ugly number from the three subsequence.
// Every step we choose the smallest one, and move one step after,including nums with same value.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly(n);
        ugly[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        int factor2 = 2, factor3 = 3, factor5 = 5;
        for(int i = 1; i < n; ++i){
            int minNum = min(min(factor2, factor3), factor5);
            ugly[i] = minNum;
            if(factor2 == minNum)
                factor2 = 2 * ugly[++index2];
            if(factor3 == minNum)
                factor3 = 3 * ugly[++index3];
            if(factor5 == minNum)
                factor5 = 5 * ugly[++index5];
        }
        return ugly[n-1];
    }
};