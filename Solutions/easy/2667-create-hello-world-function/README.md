<h2><a href="https://leetcode.com/problems/create-hello-world-function/">2667. Create Hello World Function</a></h2><h3>Easy</h3><hr>Write a function&nbsp;<code>createHelloWorld</code>.&nbsp;It should return a new function that always returns&nbsp;<code>&quot;Hello World&quot;</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> args = []
<strong>Output:</strong> &quot;Hello World&quot;
<strong>Explanation:</strong>
const f = createHelloWorld();
f(); // &quot;Hello World&quot;

The function returned by createHelloWorld should always return &quot;Hello World&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> args = [{},null,42]
<strong>Output:</strong> &quot;Hello World&quot;
<strong>Explanation:</strong>
const f = createHelloWorld();
f({}, null, 42); // &quot;Hello World&quot;

Any arguments could be passed to the function but it should still always return &quot;Hello World&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= args.length &lt;= 10</code></li>
</ul>
<hr><h3>Submission metrics</h3><ul><li><strong>Runtime measured by LeetCode:</strong> 41 ms</li><li><strong>Memory measured by LeetCode:</strong> 53.4 MB</li></ul><h3>Big-O analysis</h3><ul><li><strong>Time:</strong> O(1)</li><li><strong>Space:</strong> O(1)</li><li><strong>Source:</strong> heuristic (low confidence)</li></ul><p><em>Conservative static estimate from javascript control flow and allocations; review before relying on it.</em></p>