<h2><a href="https://leetcode.com/problems/return-length-of-arguments-passed/">2703. Return Length of Arguments Passed</a></h2><h3>Easy</h3><hr>Write a function&nbsp;<code>argumentsLength</code> that returns the count of arguments passed to it.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> args = [5]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
argumentsLength(5); // 1

One value was passed to the function so it should return 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> args = [{}, null, &quot;3&quot;]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
argumentsLength({}, null, &quot;3&quot;); // 3

Three values were passed to the function so it should return 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>args</code>&nbsp;is a valid JSON array</li>
	<li><code>0 &lt;= args.length &lt;= 100</code></li>
</ul>
<hr><h3>Submission metrics</h3><ul><li><strong>Runtime measured by LeetCode:</strong> 59 ms</li><li><strong>Memory measured by LeetCode:</strong> 48.6 MB</li></ul><h3>Big-O analysis</h3><ul><li><strong>Time:</strong> O(1)</li><li><strong>Space:</strong> O(1)</li><li><strong>Source:</strong> heuristic (low confidence)</li></ul><p><em>Conservative static estimate from javascript control flow and allocations; review before relying on it.</em></p>