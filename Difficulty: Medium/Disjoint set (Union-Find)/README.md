<h2><a href="https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1">Disjoint set (Union-Find)</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p data-start="515" data-end="677"><span style="font-size: 14pt;">You are given n elements numbered from&nbsp;<strong>1</strong>&nbsp;to&nbsp;<strong>n</strong>. Initially, each element is in its own group and its group's representative as well. </span><span style="font-size: 14pt;">You need to process&nbsp;<strong>k</strong>&nbsp;queries of two types:</span></p>
<ul>
<li data-start="515" data-end="677"><span style="font-size: 14pt;">Type 1:&nbsp;<strong>1 x z</strong><br>Performs a <strong>UNION&nbsp;</strong>operation on elements&nbsp;<strong>x</strong>&nbsp;and&nbsp;<strong>z</strong>.&nbsp;</span><span style="font-size: 14pt;">After merging, the representative of z becomes the representative of the whole group. </span><span style="font-size: 14pt;">Merge the group containing x into the group containing z by making the representative of x point to the ultimate representative of z.</span></li>
</ul>
<ul>
<li data-start="515" data-end="677"><span style="font-size: 14pt;">Type 2:&nbsp;<strong>2 x</strong><br>Perform a&nbsp;<strong>FIND&nbsp;</strong>operation on element&nbsp;<strong>x</strong>. </span><span style="font-size: 14pt;">Output the representative of the group containing <strong>x</strong>.</span></li>
</ul>
<p><span style="font-size: 14pt;"><strong>Note:</strong><br></span></p>
<ul>
<li><span style="font-size: 18.6667px;">The representative of an element is the root of its group, i.e., the element whose parent is itself.</span></li>
<li><span style="font-size: 18.6667px;">Initially, every element is its own representative.</span></li>
</ul>
<p><strong><span style="font-size: 18.6667px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 5, k = 4, queries[] = [[2, 4], [2, 1], [1, 3, 1], [2, 3]]
<strong>Output: </strong>[4, 1, 1]
<strong>Explanation:</strong>
2 4 → Find the representative of 4. Since 4 is initially in its own group, the answer is 4.
2 1 → Find the representative of 1. Since 1 is initially in its own group, the answer is 1.
1 3 1 → Union the groups containing 3 and 1. The representative of 3 is attached to the representative of 1. So the parent of 3 becomes 1.
2 3 → Find the representative of 3. Now 3 belongs to the group whose leader is 1, so the answer is 1.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 6, k = 6, queries[] = [[1, 2, 3], [1, 4, 5], [2, 2], [2, 3], [1, 3, 5], [2, 4]]
<strong>Output: </strong>[3, 3, 5]
<strong>Explanation:</strong>
1 2 3 → Merge group of 2 into group of 3. Now 2 points to 3.
1 4 5 → Merge group of 4 into group of 5. Now 4 points to 5.
2 2 → Representative of 2 is 3.
2 3 → Representative of 3 is 3.
1 3 5 → Merge group of 3 into group of 5. Now 3 points to 5, and 2 also indirectly belongs to the same group.
2 4 → Representative of 4 is 5.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n, k ≤ 1000<br>1&nbsp;</span><span style="font-size: 18px;">≤ x, z&nbsp;</span><span style="font-size: 18px;">≤ n</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Samsung</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>union-find</code>&nbsp;