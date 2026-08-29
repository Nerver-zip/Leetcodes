<h2><a href="https://leetcode.com/problems/subarray-product-less-than-k/">713. Subarray Product Less Than K</a></h2><h3>Medium</h3><hr><p>Given an array of integers <code>nums</code> and an integer <code>k</code>, return <em>the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than </em><code>k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,5,2,6], k = 100
<strong>Output:</strong> 8
<strong>Explanation:</strong> The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3], k = 0
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>6</sup></code></li>
</ul>
<hr><h3>Submission metrics</h3><ul><li><strong>Runtime measured by LeetCode:</strong> 5 ms</li><li><strong>Memory measured by LeetCode:</strong> 65.3 MB</li></ul><h3>Big-O analysis</h3><ul><li><strong>Time:</strong> O(n)</li><li><strong>Space:</strong> O(n)</li><li><strong>Source:</strong> heuristic (low confidence)</li></ul><p><em>Conservative static estimate from cpp control flow and allocations; review before relying on it.</em></p>