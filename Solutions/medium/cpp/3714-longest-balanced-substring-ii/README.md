<h2><a href="https://leetcode.com/problems/longest-balanced-substring-ii/">3714. Longest Balanced Substring II</a></h2><h3>Medium</h3><hr><p>You are given a string <code>s</code> consisting only of the characters <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code>.</p>

<p>A <strong><span data-keyword="substring-nonempty">substring</span></strong> of <code>s</code> is called <strong>balanced</strong> if all <strong>distinct</strong> characters in the <strong>substring</strong> appear the <strong>same</strong> number of times.</p>

<p>Return the <strong>length of the longest balanced substring</strong> of <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;abbac&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The longest balanced substring is <code>&quot;abba&quot;</code> because both distinct characters <code>&#39;a&#39;</code> and <code>&#39;b&#39;</code> each appear exactly 2 times.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;aabcc&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The longest balanced substring is <code>&quot;abc&quot;</code> because all distinct characters <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code> and <code>&#39;c&#39;</code> each appear exactly 1 time.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;aba&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>One of the longest balanced substrings is <code>&quot;ab&quot;</code> because both distinct characters <code>&#39;a&#39;</code> and <code>&#39;b&#39;</code> each appear exactly 1 time. Another longest balanced substring is <code>&quot;ba&quot;</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> contains only the characters <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code>.</li>
</ul>
<hr><h3>Submission metrics</h3><ul><li><strong>Runtime measured by LeetCode:</strong> 1686 ms</li><li><strong>Memory measured by LeetCode:</strong> 246.8 MB</li></ul><h3>Big-O analysis</h3><ul><li><strong>Time:</strong> O(n²)</li><li><strong>Space:</strong> O(1)</li><li><strong>Source:</strong> heuristic (low confidence)</li></ul><p><em>Conservative static estimate from cpp control flow and allocations; review before relying on it.</em></p>