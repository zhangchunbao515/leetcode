# [478. Generate Random Point in a Circle (Medium)](https://leetcode.com/problems/generate-random-point-in-a-circle/)

<p>Given the radius and x-y positions of the center of a circle, write a function <code>randPoint</code>&nbsp;which&nbsp;generates a uniform random&nbsp;point in the circle.</p>

<p>Note:</p>

<ol>
	<li>input and output values are&nbsp;in&nbsp;<a href="https://www.webopedia.com/TERM/F/floating_point_number.html" target="_blank">floating-point</a>.</li>
	<li>radius and x-y position of the center of the circle is passed into the class constructor.</li>
	<li>a point on the circumference of the circle is considered to be&nbsp;in the circle.</li>
	<li><code>randPoint</code>&nbsp;returns&nbsp;a size 2 array containing x-position and y-position of the random point, in that order.</li>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: 
</strong><span id="example-input-1-1">["Solution","randPoint","randPoint","randPoint"]
</span><span id="example-input-1-2">[[1,0,0],[],[],[]]</span>
<strong>Output: </strong><span id="example-output-1">[null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: 
</strong><span id="example-input-2-1">["Solution","randPoint","randPoint","randPoint"]
</span><span id="example-input-2-2">[[10,5,-7.5],[],[],[]]</span>
<strong>Output: </strong><span id="example-output-2">[null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]</span></pre>
</div>

<p><strong>Explanation of Input Syntax:</strong></p>

<p>The input is two lists:&nbsp;the subroutines called&nbsp;and their&nbsp;arguments.&nbsp;<code>Solution</code>'s&nbsp;constructor has three arguments, the radius, x-position of the center, and y-position of the center of the circle. <code>randPoint</code> has no arguments.&nbsp;Arguments&nbsp;are&nbsp;always wrapped with a list, even if there aren't any.</p>
</div>


**Companies**:  
[Leap Motion](https://leetcode.com/company/leap-motion)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Random](https://leetcode.com/tag/random/), [Rejection Sampling](https://leetcode.com/tag/rejection-sampling/)

**Similar Questions**:
* [Random Point in Non-overlapping Rectangles (Medium)](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/)

## Solution 1. Rejection Sampling

See explanations [here](https://leetcode.com/problems/generate-random-point-in-a-circle/solution/)

```cpp
// OJ: https://leetcode.com/problems/generate-random-point-in-a-circle/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/generate-random-point-in-a-circle/solution/
class Solution {
private:
    double radius, x_center, y_center, area;
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};
public:
    Solution(double radius, double x_center, double y_center) : radius(radius), x_center(x_center), y_center(y_center) {
    }
    
    vector<double> randPoint() {
        double x0 = x_center - radius;
        double y0 = y_center - radius;
        while (true) {
            double x = x0 + uni(rng) * 2 * radius;
            double y = y0 + uni(rng) * 2 * radius;
            if (sqrt(pow(x - x_center, 2) + pow(y - y_center, 2)) > radius) continue;
            return { x, y };
        }
    }
};
```

## Solution 2. Inverse Transform Sampling (Math)

```cpp
// OJ: https://leetcode.com/problems/generate-random-point-in-a-circle/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/generate-random-point-in-a-circle/solution/
class Solution {
private:
    double radius, x_center, y_center, area;
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};
public:
    Solution(double radius, double x_center, double y_center) : radius(radius), x_center(x_center), y_center(y_center) {
    }
    vector<double> randPoint() {
        double d = radius * sqrt(uni(rng)), theta = uni(rng) * 2 * M_PI;
        return { x_center + d * cos(theta), y_center + d * sin(theta) };
    }
};
```