<h2><a href="https://leetcode.com/problems/reverse-nodes-in-k-group/">25. Reverse Nodes in k-Group</a></h2><h3>Hard</h3><hr><p>Given the <code>head</code> of a linked list, reverse the nodes of the list <code>k</code> at a time, and return <em>the modified list</em>.</p>

<p><code>k</code> is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of <code>k</code> then left-out nodes, in the end, should remain as it is.</p>

<p>You may not alter the values in the list&#39;s nodes, only nodes themselves may be changed.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [2,1,4,3,5]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], k = 3
<strong>Output:</strong> [3,2,1,4,5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 5000</code></li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong> Can you solve the problem in <code>O(1)</code> extra memory space?</p>
<hr><h3>Submission metrics</h3><ul><li><strong>Runtime measured by LeetCode:</strong> 0 ms</li><li><strong>Memory measured by LeetCode:</strong> 16.5 MB</li></ul><h3>Big-O analysis</h3><ul><li><strong>Time:</strong> O(n)</li><li><strong>Space:</strong> O(1)</li><li><strong>Source:</strong> heuristic (low confidence)</li></ul><p><em>Conservative static estimate from cpp control flow and allocations; review before relying on it.</em></p>