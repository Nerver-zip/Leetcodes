<h2><a href="https://leetcode.com/problems/reverse-pairs/">493. Reverse Pairs</a></h2><h3>Hard</h3><hr><p>Given an integer array <code>nums</code>, return <em>the number of <strong>reverse pairs</strong> in the array</em>.</p>

<p>A <strong>reverse pair</strong> is a pair <code>(i, j)</code> where:</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; nums.length</code> and</li>
	<li><code>nums[i] &gt; 2 * nums[j]</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,2,3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The reverse pairs are:
(1, 4) --&gt; nums[1] = 3, nums[4] = 1, 3 &gt; 2 * 1
(3, 4) --&gt; nums[3] = 3, nums[4] = 1, 3 &gt; 2 * 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,4,3,5,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The reverse pairs are:
(1, 4) --&gt; nums[1] = 4, nums[4] = 1, 4 &gt; 2 * 1
(2, 4) --&gt; nums[2] = 3, nums[4] = 1, 3 &gt; 2 * 1
(3, 4) --&gt; nums[3] = 5, nums[4] = 1, 5 &gt; 2 * 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
<hr><h3>Submission metrics</h3><ul><li><strong>Runtime measured by LeetCode:</strong> 677 ms</li><li><strong>Memory measured by LeetCode:</strong> 222.6 MB</li></ul><h3>Big-O analysis</h3><ul><li><strong>Time:</strong> O(log n)</li><li><strong>Space:</strong> O(n)</li><li><strong>Source:</strong> heuristic (low confidence)</li></ul><p><em>Conservative static estimate from cpp control flow and allocations; review before relying on it.</em></p>