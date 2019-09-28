# [279. Perfect Squares (Medium)](https://leetcode.com/problems/perfect-squares/)

<p>Given a positive integer <i>n</i>, find the least number of perfect square numbers (for example, <code>1, 4, 9, 16, ...</code>) which sum to <i>n</i>.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> <i>n</i> = <code>12</code>
<b>Output:</b> 3 
<strong>Explanation: </strong><code>12 = 4 + 4 + 4.</code></pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> <i>n</i> = <code>13</code>
<b>Output:</b> 2
<strong>Explanation: </strong><code>13 = 4 + 9.</code></pre>

**Companies**:  
[Lyft](https://leetcode.com/company/lyft), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Count Primes (Easy)](https://leetcode.com/problems/count-primes/)
* [Ugly Number II (Medium)](https://leetcode.com/problems/ugly-number-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/perfect-squares/
// Author: github.com/lzl124631x
// Time: O(NS) where S is the count of square numbers less than n.
// Space: O(N)
class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n + 1, INT_MAX);
        for (int i = 1; i * i <= n; ++i) v[i * i] = 1;
        for (int i = 1; i <= n; ++i) {
            if (v[i] == 1) continue;
            for (int j = 1; j * j < i; ++j) {
                v[i] = min(v[i], 1 + v[i - j * j]);
            }
        }
        return v[n];
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/perfect-squares/
// Author: github.com/lzl124631x
// Time: O(NS) where S is the count of square numbers less than n.
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics
class Solution {
public:
    int numSquares(int n) {
        static vector<int> v{0};
        while (v.size() <= n) {
            int m = v.size(), minVal = INT_MAX;
            for (int j = 1; j * j <= m; ++j) {
                minVal = min(minVal, 1 + v[m - j * j]);
            }
            v.push_back(minVal);
        }
        return v[n];
    }
};
```