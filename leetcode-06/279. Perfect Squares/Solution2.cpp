// Static Dynamic Programming

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Since cntPerfectSquares is a static vector, if 
        // cntPerfectSquares.size() > n, we have already calculated the result 
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});
        // While cntPerfectSquares.size() <= n, we need to incrementally 
        // calculate the next result until we get the result for n.
        while (cntPerfectSquares.size() <= n) {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++) {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }
            cntPerfectSquares.push_back(cntSquares);
        }
        return cntPerfectSquares[n];
    }
};