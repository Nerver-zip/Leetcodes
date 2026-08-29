<h2><a href="https://leetcode.com/problems/reverse-linked-list-ii/">92. Reverse Linked List II</a></h2><h3>Medium</h3><hr><p>Given the <code>head</code> of a singly linked list and two integers <code>left</code> and <code>right</code> where <code>left &lt;= right</code>, reverse the nodes of the list from position <code>left</code> to position <code>right</code>, and return <em>the reversed list</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], left = 2, right = 4
<strong>Output:</strong> [1,4,3,2,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [5], left = 1, right = 1
<strong>Output:</strong> [5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>n</code>.</li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>-500 &lt;= Node.val &lt;= 500</code></li>
	<li><code>1 &lt;= left &lt;= right &lt;= n</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you do it in one pass?<hr><h3>Submission metrics</h3><ul><li><strong>Runtime measured by LeetCode:</strong> 0 ms</li><li><strong>Memory measured by LeetCode:</strong> 11.1 MB</li></ul><h3>Big-O analysis</h3><ul><li><strong>Time:</strong> O(n)</li><li><strong>Space:</strong> O(1)</li><li><strong>Source:</strong> heuristic (low confidence)</li></ul><p><em>Conservative static estimate from cpp control flow and allocations; review before relying on it.</em></p>