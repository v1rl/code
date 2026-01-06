括号匹配模板题扩展——带回退的括号匹配

[C - Brackets Stack Query](https://atcoder.jp/contests/abc428/tasks/abc428_c)

对数位与区间的理解——区间完全平方数的个数，但区间不连续

[D - 183184](https://atcoder.jp/contests/abc428/tasks/abc428_d)

树的直径性质——距离每个点最远的下标最大的点

[E - Farthest Vertex](https://atcoder.jp/contests/abc428/tasks/abc428_e)



博弈论反向dp，从结果的必胜/必败态逐步转移到初始状态

[D - The Simple Game](https://atcoder.jp/contests/abc427/tasks/abc427_d)

题目需要的信息可以在执行BFS的同时得到很好的维护——除了坐标以外还需要维护更多信息的多维度BFS

[E - Wind Cleaning](https://atcoder.jp/contests/abc427/tasks/abc427_e)

单调增性质下的简单桶贪心

[C - Upgrade Required](https://atcoder.jp/contests/abc426/tasks/abc426_c)

维护连续且相等的序列

[D - Pop and Insert](https://atcoder.jp/contests/abc426/tasks/abc426_d)



## 二分

二分与二分的特判

[F - Pyramid Alignment](https://atcoder.jp/contests/abc428/tasks/abc428_f)

贪心发现答案符合对条件满足与否的两面可划分性，随后二分答案

[C-诗超绊_牛客小白月赛123内测](https://ac.nowcoder.com/acm/contest/120495/C)

离散化与区间优化

[D - On AtCoder Conference](https://atcoder.jp/contests/abc429/tasks/abc429_d)



## 动态规划

带约束的最优问题

[D - Robot Customize](https://atcoder.jp/contests/abc431/tasks/abc431_d)



## 最短路

边权有一定特殊性质的最短路

[D-春日影_牛客小白月赛123内测](https://ac.nowcoder.com/acm/contest/120495/D)



## 带权并查集

带权并查集关系与权值的传递性

[F-明弦音_牛客小白月赛123内测](https://ac.nowcoder.com/acm/contest/120495/F)



## 数论分块

分子离散变化（且变化量和整除结果相关）的数论分块——先得到整除结果相同的范围，再计算范围内可能出现多少个离散的分子

[Problem - D2 - Codeforces](https://codeforces.com/contest/2169/problem/D2)



## 暴力n^2的序列问题

能得到数学公式——推导化简数学公式得到函数f(x)，O(n)维护函数最优

[Problem - C - Codeforces](https://codeforces.com/contest/2169/problem/C)



## 序列合并

总是相邻做合并——用双向链表做连接，并在合并时修改双向链表

[Problem - C - Codeforces](https://codeforces.com/contest/2166/problem/C)



## 扩展欧几里得

解决环上移动(取模)取最值时次数问题——转换问题为取模式，再转换取模式为exgcd式，再根据裴蜀定理约束得到未知数

[C-一日之计在于晨_广州大学第十八届ACM大学生程序设计竞赛（同步赛）](https://ac.nowcoder.com/acm/contest/77448/C)



## 网络流

数据范围较小，判定题目在一定条件约束下能否达到目标次数，且约束条件可以由拆点、建边、设置容量施加给网络流



可将图上的点划分为两部分，分别连接起点和终点；颜色不同的约束、颜色变化的约束可由拆点和设置容量完成

[G - Colorful Christmas Tree](https://atcoder.jp/contests/abc437/tasks/abc437_g)



## 树形结构

题目信息可构造出一棵树，题目需求可转换为对树上各点的操作

[E - Sort Arrays](https://atcoder.jp/contests/abc437/tasks/abc437_e)



## 数学变换

对绝对值进行数学变化简化求解流程

[D - Sum of Differences](https://atcoder.jp/contests/abc437/tasks/abc437_d)

[F - Manhattan Christmas Tree 2](https://atcoder.jp/contests/abc437/tasks/abc437_f)

对存在多个规则的贪心进行数学变换，将复数聚合成单一规则

[C - Reindeer and Sleigh 2](https://atcoder.jp/contests/abc437/tasks/abc437_c)



小知识点：

(x + add - l) % (r - l + 1) + l
$$
\begin{aligned}
|x - X_i| + |y - Y_i|
&= \max\{x - X_i,\; -(x - X_i)\} + \max\{y - Y_i,\; -(y - Y_i)\} \\
&= \max\{
x - X_i + y - Y_i,\;
x - X_i - y + Y_i,\;
- x + X_i + y - Y_i,\;
- x + X_i - y + Y_i
\} \\
&= \max\Big\{
\max\{(x + y) - (X_i + Y_i),\; -(x + y) + (X_i + Y_i)\}, \\
&\qquad\quad
\max\{(x - y) - (X_i - Y_i),\; -(x - y) + (X_i - Y_i)\}
\Big\} \\
&= \max\Big(
\big|(x + y) - (X_i + Y_i)\big|,\;
\big|(x - y) - (X_i - Y_i)\big|
\Big)
\end{aligned}
$$


代码习惯：

while循环按照先执行在变化来写，则循环内容应该为 while(数据在有效范围内)

https://leetcode.cn/problems/count-negative-numbers-in-a-sorted-matrix/?envType=daily-question&envId=2025-12-28
