// Description:
// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.
// Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
// However, when you guess a particular number x, and you guess wrong, you pay $x.
// You win the game when you guess the number I picked.

// Example:
// n = 10, I pick 8.
// First round:  You guess 5, I tell you that it's higher. You pay $5.
// Second round: You guess 7, I tell you that it's higher. You pay $7.
// Third round:  You guess 9, I tell you that it's lower. You pay $9.
// Game over. 8 is the number I picked.
// You end up paying $5 + $7 + $9 = $21.

// Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

// Dynamic Programming Solution: top-down
// MinMax

#include<vector>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        return solve(1, n, dp);
    }
    
    int solve(int l, int r, vector<vector<int>> &dp) {
        if (l >= r) return 0;
        if (dp[l][r] != INT_MAX) return dp[l][r];
        for (int i = l; i <= r; ++i) {
            // we don't know whether high or low, just pick worst case.
            dp[l][r] = min(dp[l][r], max(i+solve(l, i-1, dp), i+solve(i+1, r, dp)));
        }
        return dp[l][r];
    }
};