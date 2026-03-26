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



## 贪心

> 不要去纠结严格证明，每个题都去追求严格证明，浪费时间、收益很低
>
> 大量累积贪心的经验，重点不是证明，而是题目的特征，以及贪心方式的特征，做好总结方便借鉴
>
> 关注题目数据量，题目的解可能来自贪心，也很可能不是，如果数据量允许，能不用贪心就不用（稳）
>
> 掌握用对数器验证的技巧

- 排序相关

[1029. 两地调度 - 力扣（LeetCode）](https://leetcode.cn/problems/two-city-scheduling/description/)（先极限法设定一个基底，然后在基底上考虑如何贪心地修改）



> 这两个函数的设计初衷是维护一个**保持有序的插入区间**。
> **lower_bound** 是能保持序列有序的**第一个**可插入位置。
> **upper_bound** 是能保持序列有序的**最后一个**可插入位置。
>
> 符合条件的最值查询：
>
> 找符合条件的最右点（找比目标小的最大的点）
> 单调性视角：一般左侧全是符合条件的点，右侧全是不符合条件的点，于是正向
> 指针遍历视角：`while(cur符合条件) cur++`，最后`cur-1`即为目标点
> 函数二分视角：`upper_bound(tar) - 1`即为目标点
> 手写二分视角：`if(mid符合条件) l = mid; else r = mid - 1`，其中`符合条件`一般写一个check(mid)来判定
>
> 找符合条件的最左点（找比目标大的最小的点）
> 单调性视角：一般右侧全是符合条件的点，左侧全是不符合条件的点，于是反向
> 指针遍历视角：`while(cur符合条件) cur --`，最后`cur+1`即为目标点
> 函数二分视角：`lower_bound(tar)` 即为目标点
> 手写二分视角：`if(mid符合条件) r = mid; else l = mid + 1`，其中`符合条件`一般写一个check(mid)来判定

## 二分

二分与二分的特判

[F - Pyramid Alignment](https://atcoder.jp/contests/abc428/tasks/abc428_f)

条件真假单调情况下，查找符合条件的最值

[C-诗超绊_牛客小白月赛123内测](https://ac.nowcoder.com/acm/contest/120495/C)

[C-智乃的草坪_2026牛客寒假算法基础集训营5](https://ac.nowcoder.com/acm/contest/120565/C)

离散化与区间优化

[D - On AtCoder Conference](https://atcoder.jp/contests/abc429/tasks/abc429_d)

对动态有序集的二分——用 `set `维护有序集

[E-智乃的最大子段和取模_2026牛客寒假算法基础集训营5](https://ac.nowcoder.com/acm/contest/120565/E)（负数取模意义下的最大，找恰大于x的最小值）

跟随二分差量维护数据集

 [NOIP 2012 提高组 借教室 - 洛谷](https://www.luogu.com.cn/problem/P1083)





## 倍增

> 注意单独开变量存倍增时维护的信息

若点集中的任意一个点都满足"入度无所谓，但出度一定为1"，则该点集中的高数量级次数移动，可以通过维护二进制倍增跳表快速实现
倍增LCA是向上倍增，其原理便是，树上每个点一定只存在一个父节点
但倍增跳表可以维护的信息有限，一般只能是移动的终点和路径上每个点信息的简单求和

在点集中，每个点都有且仅有一个固定的去向，形成复数个链与环的聚合体

[E - Heavy Buckets](https://atcoder.jp/contests/abc438/tasks/abc438_e)

[2836. 在传球游戏中最大化函数值](https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game/description/)



## 预处理

- 差分与前缀和

> 二维区间差分：$g[x][l]++、g[y+1][r+1]++、g[x][r+1]--、g[y+1][l]--$
>
> 二维前缀和维护：$s[x-1][y]+s[x][y-1]-s[x-1][y-1]+a[x][y]$
>
> 二维前缀和查询：$s[y][r]-s[x-1][r]-s[y][l-1]+s[x-1][l-1]$

[D - Clouds](https://atcoder.jp/contests/abc434/tasks/abc434_d)

[C - Rotate and Sum Query](https://atcoder.jp/contests/abc425/tasks/abc425_c)（带偏移量的前缀和）

[E - Sum of Subarrays](https://atcoder.jp/contests/abc423/tasks/abc423_e)（推数学式子转换目标函数为多项前缀和的聚合）

> 将选中条件转换为不等式$$L \le l \le j \le r \le R$$
> 得到权重 $W_j = (j - L + 1) \times (R - j + 1)$。
> 得到公式$\text{Ans} = \sum_{j=L}^{R} A_j \cdot (j - L + 1)(R - j + 1)$。
> 分配律拆开得到$$\text{Ans} = - \sum (j^2 A_j) + (L+R) \sum (j A_j) - (L-1)(R+1) \sum A_j$$

[E - A > B substring](https://atcoder.jp/contests/abc441/tasks/abc441_e)（推数学式子转换目标函数为多项前缀和的聚合）

zcy105problem2（维护多个前缀和来判定子串是否为合法字符串）



- 前后缀分解，预处理前缀（有固定的左边界起点）和后缀（有固定的右边界终点）

[D-小红的异或分组](https://ac.nowcoder.com/acm/contest/128768/D)（分为三部分，则第一部分一定是前缀，第三部分一定是后缀）

[689. 三个无重叠子数组的最大和 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/description/)（预处理前后缀，然后枚举中间）

[P8776 蓝桥杯 2022 省 A 最长不下降子序列 - 洛谷](https://www.luogu.com.cn/problem/solution/P8776)

- 预处理树上节点信息

[F-小红删树](https://ac.nowcoder.com/acm/contest/128768/F)（预处理点的非叶邻节点个数）





## 折半查找

> 让问题的数量级从 $a^n$ 变成 $a^{n / 2}$ + 合并或其他操作的复杂度(通常为log或小范围的n)
>
> 通常底数a为2，数量级n为40左右

[G - Small Multiple 2](https://atcoder.jp/contests/abc423/tasks/abc423_g)（底数为10，数量级为10）



## BFS

需要按照层数统一执行修改操作而分层执行的BFS

[D - Ulam-Warburton Automaton](https://atcoder.jp/contests/abc425/tasks/abc425_d)

要求某点到**任意**符合特定条件的点的距离，考虑对符合特定条件的点做反向多源BFS

[J-终于再见_2026牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/120562/J)



> 题目数据范围下可以直接**暴力搜索**最优结果

## DFS与剪枝

[G-真白的幻觉_2026牛客寒假算法基础集训营4](https://ac.nowcoder.com/acm/contest/120564/G)（选几位）



## 滑动窗口

删掉1个数字后长度为k的子数组最大累加和

> 找到每个长度为k+1窗口的最小值，用总和减去最小值即为可行答案之一



## 数论

- 质因子相关

[C-小红的数字查找](https://ac.nowcoder.com/acm/contest/128768/C)（完全平方数的所有质因子都是偶数个）



> 用于解决无法贪心的策略选择问题
> 通过状态设计只保留局部最优的解空间
> 通过状态转移逐步扩张局部最优的解空间



> 状态的维度和属性怎么设计？
> 怎么执行状态转移？
> 在转移之前，需要对状态执行怎样的初始化？
> 是否可以降维或滚动优化？

## 动态规划

> 设计状态、状态的属性、状态的转移，使得我们能得到的所有状态能不重不漏地表示解空间
> 无后效性——任何情况下的**进一步转移都只和当前状态有关**，和之前选了什么，怎么选的无关
> 最优子结构——可由局部最优解空间逐步扩张得到全局最优解空间
>
> dp的初始化
> 要么定义一个能够让开头同后续整个dp一起使用同一个流程的（范围外的）初始边界
> [G - Set list](https://atcoder.jp/contests/abc424/tasks/abc424_g)
> [E-立希的扫雷构造_2026牛客寒假算法基础集训营4](https://ac.nowcoder.com/acm/contest/120564/E)（单独处理初始点，转移时额外做一定判断）
>
> 要么单独对开头做初始化
> [D - 2x2 Erasing 2](https://atcoder.jp/contests/abc424/tasks/abc424_d)（单独处理初始第一行）

带约束的最优问题

[D - Robot Customize](https://atcoder.jp/contests/abc431/tasks/abc431_d)

最长xx子序列的长度等价于最长不xx子序列的最小划分数，且得到的g数组为一个xx子序列

[E - Kite](https://atcoder.jp/contests/abc439/tasks/abc439_e)

在状态的转移阶段找到统一多个状态（On->O1）的方法，从而做时间上的优化

[G - Domino Arrangement](https://atcoder.jp/contests/abc435/tasks/abc435_g)

前后缀分解

[G - Range Knapsack Query](https://atcoder.jp/contests/abc426/tasks/abc426_g)（区间背包）

[F - Must Buy](https://atcoder.jp/contests/abc441/tasks/abc441_f)（删除一个物品后的背包问题 / 物品贡献分析）

带有时间后效性的背包问题——先贪心排序消除后效性

[P1417 烹调方案 - 洛谷](https://www.luogu.com.cn/problem/P1417)（非常规背包最好都使用”恰好“而非”至少“）





## DP计数

状压dp计数

[F - Inserting Process](https://atcoder.jp/contests/abc425/tasks/abc425_f)（一维状压，对同行的相邻转移限制）

[D - 2x2 Erasing 2](https://atcoder.jp/contests/abc424/tasks/abc424_d)（二维状压，对不同行的2*2转移限制）

[25牛客寒假第一场 Fmy]()（每个bit存有对应信息，只有信息合法的bit才可以执行转移）

线性dp计数

[H-Blackboard_2026牛客寒假算法基础集训营1](https://ac.nowcoder.com/acm/contest/120561/H)



## 最短路

边权有一定特殊性质的最短路

[D-春日影_牛客小白月赛123内测](https://ac.nowcoder.com/acm/contest/120495/D)



## 反向思考

正向处理问题困难时，考虑反向处理

- 正向删除困难，但反向扩张简单

[E-小L的空投](https://ac.nowcoder.com/acm/contest/120566/E)



## 带权并查集

带权并查集关系与权值的传递性

[F-明弦音_牛客小白月赛123内测](https://ac.nowcoder.com/acm/contest/120495/F)





## 数论分块

分子离散变化（且变化量和整除结果相关）的数论分块——先得到整除结果相同的范围，再计算范围内可能出现多少个离散的分子

[Problem - D2 - Codeforces](https://codeforces.com/contest/2169/problem/D2)



## 质因子分解

约数个数、约数之和

对n!进行质因子分解

[樱花](https://ybt.ssoier.cn/problem_show.php?pid=1624)





## 暴力n^2的双指针问题

能得到数学公式——推导化简数学公式得到函数f(x)，O(n)维护函数最优

[Problem - C - Codeforces](https://codeforces.com/contest/2169/problem/C)

通过预处理省略掉一个指针的遍历

[D - Tail of Snake](https://atcoder.jp/contests/abc438/tasks/abc438_d)（集合中的元素全部加上或减去一个相同的值会影响最值大小，但不会影响最值归属）





## 双指针模拟

- 尺取法，一轮操作结束后让左指针等于右指针（+1)

```cpp
for(auto y : vec[i]) {
    if(y > lst) {
        seg[i].push_back({lst, y - 1, ++ cnt});
    }
    lst = y + 1;
}
```

[C-炮火轰炸_2026牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/120562/C)（取两段数组的相交部分）

- 一个指针跨度恒定为1，另一个指针跨度不定

```cpp
i64 pre = 0;
for(int i = l, j = mid + 1; i <= mid; i ++) {
    while(j <= r && ans[p[i]] >= val[q[j]]) {
        pre += a[q[j]];
        j ++;
    }
    ans[p[i]] += pre;
}
```

[G-宝藏拾取_2026牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/120562/G)

[983. 最低票价 - 力扣（LeetCode）](https://leetcode.cn/problems/minimum-cost-for-tickets/description/)

- 两个指针跨度都不定，执行到某一指针结束为止

```cpp
while(x < a.size() && y < b.size()) {
    if(a[x][1] < b[y][1]) {
        if(a[x][1] >= b[y][0]) {
            dsu.merge(a[x][2], b[y][2]);
        }
        x ++;
    } else {
        if(b[y][1] >= a[x][0]) {
            dsu.merge(a[x][2], b[y][2]);
        }
        y ++;
    }
}
```

[C-炮火轰炸_2026牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/120562/C)（取两段数组的相交部分）

- 两个指针跨度都不定，执行到两个指针都结束为止

```cpp
while(i <= mid || j <= r) {
    if(i <= mid && (j == r + 1 || val[q[i]] < val[q[j]] - lv)) {
        lst = val[q[i]];
        lv += a[q[i]];
        tmp[k ++] = q[i];
        i ++;
    } else {
        lst = max(lst, val[q[j]] - lv);
        val[q[j]] = lst;
        tmp[k ++] = q[j];
        j ++;
    }
}
```

[G-宝藏拾取_2026牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/120562/G)

- 顺序表上连续的元素作为连通块统一处理（注意尾操作）

```cpp
int ans = 0, res = 0;
for(int i = 0; i < n; i ++) {
	if(i != 0 && a[i] != a[i - 1]) {
		ans = max(ans, res);
        res = 0;
	}
    res ++;
}
ans = max(ans, res);
```

[C-智乃的草坪_2026牛客寒假算法基础集训营5](https://ac.nowcoder.com/acm/contest/120565/C)（区间覆盖问题）



## 数位字符串分类讨论

[G-Digital Folding_2026牛客寒假算法基础集训营1](https://ac.nowcoder.com/acm/contest/120561/G)



## 序列合并

总是相邻做合并——用双向链表做连接，并在合并时修改双向链表

[Problem - C - Codeforces](https://codeforces.com/contest/2166/problem/C)



## 扩展欧几里得（exgcd）

解决环上移动(取模)取最值时次数问题——转换问题为取模式，再转换取模式为exgcd式，再根据裴蜀定理约束得到未知数

[C-一日之计在于晨_广州大学第十八届ACM大学生程序设计竞赛（同步赛）](https://ac.nowcoder.com/acm/contest/77448/C)

解决线性同余方程lce（linear congruence equation）

[G - Small Multiple 2](https://atcoder.jp/contests/abc423/tasks/abc423_g)





## 网络流

数据范围较小，判定题目在一定条件约束下能否达到目标次数，且约束条件可以由拆点、建边、设置容量施加给网络流



可将图上的点划分为两部分，分别连接起点和终点；颜色不同的约束、颜色变化的约束可由拆点和设置容量完成

[G - Colorful Christmas Tree](https://atcoder.jp/contests/abc437/tasks/abc437_g)



## 树形结构

题目信息可构造出一棵树，题目需求可转换为对树上各点的操作

[E - Sort Arrays](https://atcoder.jp/contests/abc437/tasks/abc437_e)

[E. Jerry and Tom - Codeforces](https://codeforces.com/contest/2188/problem/E)



## DSU ON TREE

[E. Jerry and Tom - Codeforces](https://codeforces.com/contest/2188/problem/E)



## MEX性质

$$\sum \text{MEX}(S) = \sum_{k=1}^{n} P(\text{MEX}(S) \ge k)$$

[F - Sum of Mex](https://atcoder.jp/contests/abc438/tasks/abc438_f)（从找mex恰好为k的情况到找mex至少为k的情况）



## 最近公共祖先（LCA）

与LCA相关的树上计数问题

[F - Sum of Mex](https://atcoder.jp/contests/abc438/tasks/abc438_f)（将路径覆盖最小点集区间化，并借助LCA维护其严格继承的拓展）





## 双指针遍历

[F-小红的提拉米苏配方 牛客周赛 Round 128](https://ac.nowcoder.com/acm/contest/127240/F)

[E. Jerry and Tom - Codeforces](https://codeforces.com/contest/2188/problem/E)



> ### 仿射变换 (Affine Transformation)
>
> 从数学角度看，这种形式 $f(x) = ax + b$ 被称为仿射变换。
>
> 它的核心优势在于封闭性（Composition）：两个仿射变换叠加之后，仍然是一个仿射变换。
>
> - 变换 1：$y = k_1 x + b_1$
> - 变换 2：$z = k_2 y + b_2$
> - 叠加后：$z = k_2(k_1 x + b_1) + b_2 = (k_1 k_2) x + (k_2 b_1 + b_2)$
>
> 叠加后的式子依然符合 $f(x) = ax + b$ 的原来新的乘数是 $k_{new} = k_1 k_2$，新的加数是 $b_{new} = k_2 b_1 + b_2$。
>
> 在算法中，通常是将形如 $x = kx + b$ 的重复变换用懒标记mul和add维护
>
> 假定我们维护值为val，真实值为x
> 初始时`val = x`，即`mul = 1，add = 0`
> 每次变换后`mul *= t.mul，add = t.mul * add + t.add`
> 任意次变换下，当前元素的值`val`总是满足`val = mul * x + add`

## 线段树

线段树维护懒标记的前提是标记必须具有**封闭性 (Closure)**。即：两个操作叠加后，仍然是同一种类型的操作。

区间查询操作总是全集的懒标记数据结构

[G - Domino Arrangement](https://atcoder.jp/contests/abc435/tasks/abc435_g)

用区间最值处理对区间的括号匹配判定

[F - Adding Chords](https://atcoder.jp/contests/abc424/tasks/abc424_f)

额外维护下标的线段树

[J-MST Problem_2026牛客寒假算法基础集训营1](https://ac.nowcoder.com/acm/contest/120561/J)





> **势能分析 / 收敛性分析 (Potential Function / Convergence Analysis)**
>
> - 使用暴力模拟的数学基石。
> - 比如，虽然 $K$ 很大，但每个元素的值在不断除以 2，数值“势能”下降极快（对数级）。这意味着有效状态的总数是受限的，而非无限发散。

## 势能线段树

[F - Clearance](https://atcoder.jp/contests/abc426/tasks/abc426_f)（存在单调操作但是次数有限）

[雅礼集训 2017 Day1\] 市场 - 洛谷](https://www.luogu.com.cn/problem/U161009)（将复杂的区间操作转换为简单的区间操作）

简单势能应用问题

[E - Cut in Half](https://atcoder.jp/contests/abc424/tasks/abc424_e)（每次*2，指数上升）

[D-智乃的果子_2026牛客寒假算法基础集训营5](https://ac.nowcoder.com/acm/contest/120565/D)（每次/2，指数下降）



## 点分治

[G - Range Knapsack Query](https://atcoder.jp/contests/abc426/tasks/abc426_g)



## 扫描线

次数累计的情况下，不断覆盖(+1)或抹去(-1)一个区间，并在任意时刻查询当前被覆盖区间的长度（不论覆盖多少次，计算时都只考虑一次长度）

[E - Heavy Buckets](https://atcoder.jp/contests/abc438/tasks/abc438_e)



## 动态主席树（可持久化权值线段树）

> 一个有序的数据结构，可以等价于 总范围不再局限于全集，而是支持对下标区间子集进行相关查询的权值树状数组
>
> 具体支持的操作包括：
> kth——第 k 小数、
> queryC——值区间数的个数（小于 x 的数的个数）
> queryS——值区间数的总和（小于 x 的数的总和）、下标区间数的总和（前k小数的总和，注意不能直接加[1,k]）
> pre，suf——x 的前驱和后继

查找 x 的前驱的后继

[F - Cat exercise](https://atcoder.jp/contests/abc435/tasks/abc435_f)

查找下标区间中大于x数的个数和小于x数的总和

[G - Sum of Min](https://atcoder.jp/contests/abc438/tasks/abc438_g)



## 权值树状数组

> 一个有序的数据结构，具体支持的操作包括：
> kth——第 k 小数、
> 存点个数的sum/rangeSum——值区间数的个数（小于 x 的数的个数）
> 存点权值的sum/rangeSum——值区间数的总和（小于 x 的数的总和）、下标区间数的总和（前k小数的总和，注意不能直接加[1,k]）
> pre，suf——x 的前驱和后继

前k小数的总和（得到第k大数位置pos后先算[1,pos-1]，再根据[1,pos-1]的数量决定要算几个pos）、最大值和最小值

[F - Egoism](https://atcoder.jp/contests/abc440/tasks/abc440_f)



## 组合数学计数

子序列计数

[F - Beautiful Kadomatsu](https://atcoder.jp/contests/abc439/tasks/abc439_f)

[F - 1122 Subsequence 2](https://atcoder.jp/contests/abc433/tasks/abc433_f)（范德蒙德卷积的组合意义 $$\sum_{i} \binom{r}{i} \binom{s}{n-i} = \binom{r+s}{n}$$）

公式计数$$\frac{S!}{C_1! C_2! \dots C_N!} = \binom{C_1}{C_1} \times \binom{C_1+C_2}{C_2} \times \binom{C_1+C_2+C_3}{C_3} \times \dots \times \binom{\sum_{i=1}^N C_i}{C_N}$$

[E - Count Sequences 2](https://atcoder.jp/contests/abc425/tasks/abc425_e)





## 数学变换

数据范围极大，无法暴力解决，考虑寻找一个数学变换，使得我们能用某种数据结构一次解决大范围的数据



求两数相减的绝对值->求小于x的数的个数与大于x的数的个数

[D - Sum of Differences](https://atcoder.jp/contests/abc437/tasks/abc437_d)

求两数min求和->求小于x的数总和与大于x数的个数

[G - Sum of Min](https://atcoder.jp/contests/abc438/tasks/abc438_g)

移项使下标来源统一，拆解得到 `F[i]与F[j]` 关系的形式

[E - A > B substring](https://atcoder.jp/contests/abc441/tasks/abc441_e)

[F - Manhattan Christmas Tree 2](https://atcoder.jp/contests/abc437/tasks/abc437_f)

对存在多个规则的贪心进行数学变换，将复数聚合成单一规则

[C - Reindeer and Sleigh 2](https://atcoder.jp/contests/abc437/tasks/abc437_c)

除法与取模快速完成对集合的循环计算

[G - Sum of Min](https://atcoder.jp/contests/abc438/tasks/abc438_g)

数组可根据需求不重不漏地拆分成多个”互相独立的集合”，将数组按照集合重排从而将需要的离散数据连续排列

[G - Sum of Min](https://atcoder.jp/contests/abc438/tasks/abc438_g)（取模意义下跨度相同的分布)

连续大范围查询与Trie数据结构一起跑递归分治

[G - Sum of Min of XOR](https://atcoder.jp/contests/abc425/tasks/abc425_g)



将直觉代数化，然后对数学公式做思考和变换

[F - Adding Chords](https://atcoder.jp/contests/abc424/tasks/abc424_f)

[E - Sum of Subarrays](https://atcoder.jp/contests/abc423/tasks/abc423_e)



## 字符串哈希

> O(n)预处理后，O(1)快速比较两个字符串是否相等。可配合二分O(logn)查找任意两个字符串（包括同一字符串的不同子串，不同字符串，拼接得到的不同字符串）的LCP

[F - Concat (2nd)](https://atcoder.jp/contests/abc434/tasks/abc434_f)



## Z函数

> O(n)快速求出所有后缀子串与原字符串的LCP

利用kmp中的border数组实现动态求Z函数

[Problem - C - Codeforces](https://codeforces.com/gym/105358/problem/C)



## 排序贪心

排序本质上说就是按规则（即两两比大小的规则）排序直到有序，如果题目要求有序，但有序规则中需要满足复数个要求时，就考虑能否构造出一个将这些要求统一起来的局部排序（即两两比大小）规则

[Problem - C - Codeforces](https://codeforces.com/contest/632/problem/C)

[C - Reindeer and Sleigh 2](https://atcoder.jp/contests/abc437/tasks/abc437_c)



## 维护全体操作集

操作集只有增加元素和全体加、全体乘

[F - Beautiful Kadomatsu](https://atcoder.jp/contests/abc439/tasks/abc439_f)

操作集包括元素的增删，以及全体的仿射变换

[G - Domino Arrangement](https://atcoder.jp/contests/abc435/tasks/abc435_g)



## 三分

> 小数三分执行固定次数，整数三分缩小到长度为3开始暴力

最值->凸函数的极值

[E - Max Matrix 2](https://atcoder.jp/contests/abc433/tasks/abc433_e)



## 计算几何

> 注意在任何用到除法的地方考虑是否会发生除0错误

降低自由度

[E - Max Matrix 2](https://atcoder.jp/contests/abc433/tasks/abc433_e)



## nd，bdfs

取模后连续则原数据分块后连续+差量法[C - Striped Horse](https://atcoder.jp/contests/abc440/tasks/abc440_c)

[D - Forbidden List 2](https://atcoder.jp/contests/abc440/tasks/abc440_d)

[F - Concat (2nd)](https://atcoder.jp/contests/abc434/tasks/abc434_f)

[E - Distribute Bunnies](https://atcoder.jp/contests/abc434/tasks/abc434_e)





## 区间交集问题

> 固定段为[x,y]，讨论的移动匹配段为[l,r]，以`l、r`为基准去执行讨论，先考虑`l`再考虑`r`

[C - Flapping Takahashi](https://atcoder.jp/contests/abc434/tasks/abc434_c)

[F - Adding Chords](https://atcoder.jp/contests/abc424/tasks/abc424_f)（判定是否存在相交的区间）

[E - Heavy Buckets](https://atcoder.jp/contests/abc438/tasks/abc438_e)



## 区间计数问题

[E - A > B substring](https://atcoder.jp/contests/abc441/tasks/abc441_e)



## 指针维护问题

[D-Sequence Coloring_2026牛客寒假算法基础集训营1](https://ac.nowcoder.com/acm/contest/120561/D)（维护单调向右跳的r指针）



## 隔板法

不保证每组至少有一个元素的隔板法，C(sel+block-1,block-1)

[E - Cookies](https://atcoder.jp/contests/abc440/tasks/abc440_e)



## 优先队列

> Topk问题，本质上属于解空间巨大但目标值极小的问题，常常考虑用优先队列维护。
>
> 若状态空间的转移带有重复，需考虑设计一个不重不漏的转移逻辑

[E - Cookies](https://atcoder.jp/contests/abc440/tasks/abc440_e)

[F - K-th Largest Triplet](https://atcoder.jp/contests/abc391/tasks/abc391_f)

[E - Cut in Half](https://atcoder.jp/contests/abc424/tasks/abc424_e)（目标k很大，但是每次操作会让贡献指数增长）

优先队列随时间流逝的事件发生

[D - Long Waiting](https://atcoder.jp/contests/abc423/tasks/abc423_d)（不严格遍历时间，而是遍历离散的事件）



## set

维护一个带有修改（增删）操作的有序集

[E-智乃的最大子段和取模_2026牛客寒假算法基础集训营5](https://ac.nowcoder.com/acm/contest/120565/E)（单步扩张的同时需要二分）



## 构造

填数构造

[E - Max Matrix 2](https://atcoder.jp/contests/abc433/tasks/abc433_e)

大数构造（配合 取模化小 和 拆分讨论 使用）

[G - Small Multiple 2](https://atcoder.jp/contests/abc423/tasks/abc423_g)



## 博弈论

非常规Nim游戏

[219. 剪纸游戏 - AcWing题库](https://www.acwing.com/problem/content/description/221/)

PN游戏

[G - Substring Game](https://atcoder.jp/contests/abc433/tasks/abc433_g)



## 后缀自动机

后缀自动机的DAG转移图配合博弈论

[G - Substring Game](https://atcoder.jp/contests/abc433/tasks/abc433_g)



## 拓扑排序

- 需要按照值从大到小处理，且需要用到当前值，利用桶存储后从大到小处理


[E - Max Matrix 2](https://atcoder.jp/contests/abc433/tasks/abc433_e)

- 需要按照某个值从大到小拓扑排序，值域很大或不在意多一个logn的复杂度——维护并排序下标数组 p
- 需要按照某个值从大到小拓扑排序，值域较小——桶存储+前缀和+rank分配

后缀自动机模板



## 位运算

[Problem - D - Codeforces](https://codeforces.com/contest/2188/problem/D)（”补正“思想与枚举答案）



## 基环树

todo：[2836. 在传球游戏中最大化函数值 - 力扣（LeetCode）](https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game/description/)





## 不重不漏的递推树



## ct

不带修区间最大子数组——离线分治与合并，带修——线段树





小知识点：

(x + add - l) % (r - l + 1) + l

将曼哈顿距离公式中，绝对值中的变量来源从不同的两端点变成同一点
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

望远镜求和，对于取值范围固定(1~N)的函数f，我们令 g(i) 为值大于等于 i 的f个数，对所有函数f的求和等价于对g(1~n)的求和
$$
\sum_{k=1}^{N} k \left( c_k - c_{k+1} \right)
\;=\;
\sum_{k=1}^{N} c_k
$$
sort排序的自定义函数中，返回true代表着x严格小于y，所以x等于y时，必须返回false



CM：

可维护性，集合的每次递推都有继承的过程，可能外带少量增删

while循环按照先执行在变化来写，则循环内容应该为 while(数据在有效范围内)

https://leetcode.cn/problems/count-negative-numbers-in-a-sorted-matrix/?envType=daily-question&envId=2025-12-28





cout << fixed << setprecision(6)



这分别是题目和解析，我已经看过了并理解了题解，但题解对我来说有些跳脱了，给我讲讲是如何自然地联想到题目做法的，并说一说本题是否存在一些经典的trick



prompt



非const引用无法接收临时值



以上为分别题目和我的ac代码

我正在通过刷题的方式做目标为icpc金牌的算法训练，现在我完成了这道题，但我认为只是单纯写完是不够的，我希望能从这道题中学到更多，包括：

给这道题算法类型做一个题目归类，让我对这道题的本质有一个更深的了解，以便之后遇到类似的题目时能够更快地想出来。

给这道题做一个”假如我没有题解的上帝视角，该如何从零开始推导“的思维复盘，比如是怎么捕获到关键条件的，又是怎么将题目的关键条件做转换，并得到一个更本质、更符合需要的目标条件的。之后又怎么根据目标条件想到解题所需算法的，在套用对应算法模板的时候我应该思考哪些问题才能针对本题对模板进行特异化修改（这仅仅是我的一个举例，你可以展示任何你觉得好的思维复盘内容），以便我能快速定位关键信息，根据关键信息推断需要的算法，再以自我问答的方式快速知道针对本题应该对算法模板做出怎样的改动

另外，这是我初次思考本题时的想法，在讲解思路的最后说说我的思路和正确思路差在哪，我下次该怎么思考才能回归正确思路线："根据题目我想到了在给定一个集合S的情况下，符合条件的数的个数为上界k除以集合S所有数的lcm，但是这样的计算方式并不能确保个数恰好为集合S的大小，于是不会了"

再给根据这道题的解题方法给我一个通用解题方法论，以便之后我遇到陌生的，不会的题目时，不会脑中一片空白不知从何下手，而是可以通过思考慢慢剖析题目并最终得到解法。

最后再以顶尖选手的角度，简单给这道题从思路到代码实现的方式做一个编码流的描述，因为即便脑中已经有了本题的思路，我写代码时也总是写着写着就卡住，我希望有一个行之有效的思路快速变为代码的编码过程描述，以便我能能像顶尖选手一样脑中有了解法后，就能思路清晰，写码流畅地快速实现最终代码。

当然，除了我上面说的解析角度外，如果你认为本题还有什么值得一提的角度或主题，可以在最后加上（如果有就加上，没有的话不要硬加）



以上分别为题目和我的ac代码

我正在通过刷题的方式做目标为icpc金牌的算法训练，现在我完成了这道题，但我认为只是单纯写完是不够的，我希望能从这道题中学到更多，包括：

给这道题算法类型做一个题目归类，让我对这道题的本质有一个更深的了解，以便之后遇到类似的题目时能够更快地想出来。

给这道题做一个”假如我没有题解的上帝视角，该如何从零开始推导“的思维复盘，比如是怎么捕获到关键条件的，又是怎么将题目的关键条件做转换，并得到一个更本质、更符合需要的目标条件的。之后又怎么根据目标条件想到解题所需算法的，在套用对应算法模板的时候我应该思考哪些问题才能针对本题对模板进行特异化修改（这仅仅是我的一个举例，你可以展示任何你觉得好的思维复盘内容），以便我能快速定位关键信息，根据关键信息推断需要的算法，再以自我问答的方式快速知道针对本题应该对算法模板做出怎样的改动

再给根据这道题的解题方法给我一个通用解题方法论，以便之后我遇到陌生的，不会的题目时，不会脑中一片空白不知从何下手，而是可以通过思考慢慢剖析题目并最终得到解法。

最后再以顶尖选手的角度，简单给这道题从思路到代码实现的方式做一个编码流的描述，因为即便脑中已经有了本题的思路，我写代码时也总是写着写着就卡住，我希望有一个行之有效的思路快速变为代码的编码过程描述，以便我能能像顶尖选手一样脑中有了解法后，就能思路清晰，写码流畅地快速实现最终代码。

当然，除了我上面说的解析角度外，如果你认为本题还有什么值得一提的角度或主题，可以在最后加上（如果有就加上，没有的话不要硬加）



以上为分别题目和官方给出的题解，请结合这两个链接的内容，给我本题的思路和解法

这是一道类似的题目，下方为我完成它的代码，相应的，请



这是我整理的懒标记线段树模板代码，我已经完成了代码模板的收集整理，但我认为只记录下来是不够的，我希望能对这个算法有更深的印象，包括：

知道这个算法的基本概念是什么，是用来解决什么问题的，又是怎么实现的，让我能更熟悉这个算法的本质，使得我知道什么时候该用这个算法，看到这个算法名称时脑中不仅仅是名字，还能自动浮现出它的所有相关信息

知道这个模板的逻辑是什么，让我在考场中默写模板时不会因为不知道该干什么和忘记核心逻辑而卡住，而是可以根据模板的逻辑很顺畅地写完整个代码



以上分别为题目和ac代码，请查看并做好本题思路的解析，但不要告诉我。

我打算自行思考解决本题，在思绪堵住的时候我会询问你以获得灵感，你根据正确思路提示我即可。



以上分别为题目和ac代码，请根据它们给我本题的思路和解析，注意解析后从代码角度看看代码是怎么应用的





todo：

动态开点和换底

高难dp

[G - Haunted House](https://atcoder.jp/contests/abc440/tasks/abc440_g)

牛客技能树

tire模板重构

势能线段树

标记持久化

给模板写个md

SCC+拓扑

只有最优解才能存在属性中，其余都应该放在状态中以保证设计的dp可以覆盖全部解空间

“带下界的最小费用循环流”或者“最大权闭合子图”

构造的 自由度与限制

LCA kruskal重构树

倍增与基环树

dp与序列自动机



# 读题

**物理/自然语言映射到数学模型 (Translation)：** 不要对着题目描述空想。强迫自己用数学公式、图论模型或状态机把题目重写一遍。只要能用严格的符号表达出来，你就成功了第一步。

> 题目去故事化，捕获关键条件，条件数学化，根据数学公式推导
> *事物* $\rightarrow$ *变量*。
> *限制* $\rightarrow$ *方程/不等式*。
> *目标* $\rightarrow$ *函数表达式*。





# 思路

> 别急，别急，别急。先多想想，想明白了再写



### 明确题目类型：

**先想暴力**

- 策略选择问题：
  - 能不能用贪心直接固定最优策略？
  - 如果无法贪心，可以用什么其他算法得到最优策略？（纯暴力，某种算法优化的暴力，动态规划）
- 目标可达性判定问题：
  - 转为策略选择问题，贪心寻找是否存在抵达目标状态的策略
  - 就当判定问题做，找到能达成目标的充分条件集，执行对充分条件集的判定

- 模拟操作问题：

- 计数问题：
- 静态查询问题：
- 动态查询问题



### 宏观修正策略（Relax-Fix Pattern）

- 这是高阶数据结构题常用的思维模型：
- **Step 1 (Relax):** 假设限制不存在，执行高效的批量操作。
- **Step 2 (Check):** 询问数据结构，是否违反了限制。
- **Step 3 (Fix):** 如果违反，定位到具体点进行暴力修正。

[F - Clearance](https://atcoder.jp/contests/abc426/tasks/abc426_f)

[F - Concat (2nd)](https://atcoder.jp/contests/abc434/tasks/abc434_f)



### 降维打击（简化条件）

- 遇到棘手的限制条件，先**无视它**。
- 思考：**“如果去掉这个恶心的限制，这题是什么模型？”**
- 得到底层的思路/数据结构支撑。

[F - Clearance](https://atcoder.jp/contests/abc426/tasks/abc426_f)（线段树扩展）



### 提取题目特性（数学/逻辑性质）

- 不要把题目当成黑盒。

[J-MST Problem_2026牛客寒假算法基础集训营1](https://ac.nowcoder.com/acm/contest/120561/J)（边权可分离性、反向稀疏图）



### 模拟退化检测 (Simulation Degradation Check)

- **问自己**：如果我直接写暴力模拟，哪一步最耗时？

- **应对**：找到最耗时的操作，然后思考：

  - **计数——切换贡献视角（反向思维）**：照着过程模拟会超时，如果元素个数不多的话，能否直接统计元素的贡献呢？
  - **计数——寻找等价类执行批处理**：在这大范围的询问中，有没有哪一批数据，它们的状态、行为或执行的决策是**完全一致**的？
    找到这样的周期性或聚合性，把 $O(1)$ 的单次模拟变成 $O(Batch)$ 的批量模拟。
  - **查询——差量法**：每次查询都需要花时间查找或遍历目标集合，在查询的递进过程中，目标集合元素是否**只增不减或只减不增**，使得我们每次只需要用差量法做微调。

  [D-数字积木_2026牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/120562/D)（骨架连通块只增不减）

  [F - Sum of Mex](https://atcoder.jp/contests/abc438/tasks/abc438_f)（骨架树链只增不减）

  - **贪心——排序/堆/set的单调性**：题目是否具有或可以**排序**得到**单调性**，或者题目的决策对象是否总是**最值**且可以用**堆**维护，然后单调空间中通过指针扫描线（+最值处理）的方式得到结果
  
  [1353. 最多可以参加的会议数目 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/description/)
  
  [632. 最小区间 - 力扣（LeetCode）](https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/)
  
  - **判定查找——二分答案（跳跃式判定）**：逐一判定查找第一个符合条件的值会超时，考虑条件的真假是否存在**单调性**，使得我们可以用二分完成跳跃式判定
  - **判定查找——数学推导**：直接算出查找的目标状态
  - **询问——反向操作批处理询问**：正向逐一处理所有询问会超时，是否可以反向操作完成对询问的批处理
  
  [E-小L的空投_2026牛客寒假算法基础集训营6](https://ac.nowcoder.com/acm/contest/120566/E)（并查集易加难减）
  
  - **询问——离线思维**：
  - **查找——离散化关键点**：点的范围极大，但关键点个数有限，题目的操作与询问是否都绕关键点展开
  
  [C-炮火轰炸_2026牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/120562/C)
  
  [632. 最小区间 - 力扣（LeetCode）](https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/)

[G - Sum of Min of XOR](https://atcoder.jp/contests/abc425/tasks/abc425_g)（按最高位的值进行批处理）

[G - Sum of Min](https://atcoder.jp/contests/abc438/tasks/abc438_g)（对下标跨度相等值进行批处理）

[D - Sum of Differences](https://atcoder.jp/contests/abc437/tasks/abc437_d)（对较大和较小分别批处理）

[G - Sum of Min](https://atcoder.jp/contests/abc438/tasks/abc438_g)（对较大和较小分别批处理）

[E - Cut in Half](https://atcoder.jp/contests/abc424/tasks/abc424_e)（对某一属性相等的数据进行批处理）

[E - Sum of Subarrays](https://atcoder.jp/contests/abc423/tasks/abc423_e)（从过程视角切到贡献视角）

[G - Small Multiple 2](https://atcoder.jp/contests/abc423/tasks/abc423_g)（两段枚举判定查找 -> 单段枚举+线性同余方程直接算出另一段的目标）

[J-终于再见_2026牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/120562/J)（反向多源BFS）



小数 / 常数切入：

- 题目给定的某个数据范围极小，或是题目本身都自带极小常数（如 26 个字母、数字范围 $a_i \le 100$、位运算的 32 位），可以考虑以此入手拆分维度

[J-小L的字符串_2026牛客寒假算法基础集训营6](https://ac.nowcoder.com/acm/contest/120566/J)



### DP的局部性检验 (Locality Check)

- 问自己：**“如果我确定了当前位置的状态，我要怎么转移？需要维护哪些信息才能判断转移的合法性？”**

[D - 2x2 Erasing 2](https://atcoder.jp/contests/abc424/tasks/abc424_d)（当前行与上一行的分布信息）

[F - Inserting Process](https://atcoder.jp/contests/abc425/tasks/abc425_f)（连续相等的部分只取第一个）



### 对约束的处理顺序

- 在处理**优先级**不同的约束时，先处理优先级最高的约束（相当于仅处理第一次，之后剔除考虑不再处理）

[F-Permutation Counting_2026牛客寒假算法基础集训营1](https://ac.nowcoder.com/acm/contest/120561/F)（链式并查集模拟”只执行第一次“的操作）

- 在处理在有**偏序关系**（包含关系）的约束时
  从约束本身的角度说：先处理范围最大的约束
  从被约束的情况的角度说，是先处理所有满足约束最少（自由度最低、限制最强）的情况
  即先满足苛刻的情况，剩下的资源（自由度）自动流转给宽松的情况

[E - Max Matrix 2](https://atcoder.jp/contests/abc433/tasks/abc433_e)

[J-终于再见_2026牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/120562/J)



### 具有教育意义的贪心思路

- 策略具有周期性，整除部分贪心，余数部分暴力，有时需要额外留出**至少一个周期长度**给贪心进行“调整”。

[F-智乃的算法竞赛群友_2026牛客寒假算法基础集训营5](https://ac.nowcoder.com/acm/contest/120565/F)（通过LCM得到题目的周期性）

- 寻找**阈值**——对象的操作次数是不是有限的

（同一个对象最多只会执行一次操作）

- 寻找**不变量**——在操作过程中，是否存在什么东西是恒定不变的，
  寻找**建立在不变量基础上的变量**——在某事物恒定不变的情况下，又有什么因操作而改变

[F - Inserting Process](https://atcoder.jp/contests/abc425/tasks/abc425_f)（相对位置不变，获取顺序在变）

[H-智乃的矩阵](https://ac.nowcoder.com/acm/contest/120565/H)（黑白格总和不变，同行列的奇偶性不变，值在变）

- 可行性判定——寻找充分条件集，判定完备充分条件集，规避策略选择

- **经验题**，通过手玩例子，思考各类**非朴素情况**有什么**特殊之处**，以及导致它们有这样特殊之处的**本质**是什么

[H-智乃的矩阵](https://ac.nowcoder.com/acm/contest/120565/H)

[D-系ぎて](https://ac.nowcoder.com/acm/contest/120563/D)

[F - Concat (2nd)](https://atcoder.jp/contests/abc434/tasks/abc434_f)（交换最后一对与倒数第二对）

- 固定在某一个步骤 / 位置 / 时间点，思考当前的视界（可选集）与局部最优抉择

[1353. 最多可以参加的会议数目 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/submissions/706324682/)（加入当前天数为起点的所有会议，选择截至日期最近的会议）

[线段重合](https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37)（配合堆频繁淘汰最小值，淘汰左侧小于当前`l`的`r`）



### 等价转换

- 直接求目标很麻烦，考虑将困难目标等价转换为更简单，更容易求的目标

  - **恰好->至少**——恰好往往很难得到，是否可以通过什么方式将其转为至少

  [F - Sum of Mex](https://atcoder.jp/contests/abc438/tasks/abc438_f)（$$\sum \text{MEX}(S) = \sum_{k=1}^{n} P(\text{MEX}(S) \ge k)$$）

  

  



### 构造

> 如果你的知识储备足够多，注意力足够惊人，你可以直接顺着思路贪心得到构造方法
>
> 在没有思路情况下，考虑手玩一些小数据的合法构造样例，观察它们的规律，思考并验证为什么这样规律下的构造是合法 / 最优的，然后推导出贪心方法

[F-爱音的01串构造_2026牛客寒假算法基础集训营4](https://ac.nowcoder.com/acm/contest/120564/F)



找约束与自由度

[G - Small Multiple 2](https://atcoder.jp/contests/abc423/tasks/abc423_g)
约束：$N \equiv 0 \pmod K$ 
自由度：构造的大数最多只有 $\log_{10} K$ 位自由度

[E - Max Matrix 2](https://atcoder.jp/contests/abc433/tasks/abc433_e)
约束：每个格子需要满足$A_{i,j} \le \min(X_i, Y_j)$
自由度：各个格子限制的自由度不同，从低自由度到高自由度

[F-Permutation Counting_2026牛客寒假算法基础集训营1](https://ac.nowcoder.com/acm/contest/120561/F)

约束：值 x 必须出现在区间 + 区间所有值<= x



基底构造——难以直接从零开始做决策，先极限法设定一个基底，随后在基底的基础上做增量变换

[E-躯树の墓守](https://ac.nowcoder.com/acm/contest/120563/E)（先固定选择1~n，再从大到小修改决策）



小样例或极端样例手玩 / 打表寻找规律和性质

- 周期性构造

[I-小L的构造2_2026牛客寒假算法基础集训营6](https://ac.nowcoder.com/acm/contest/120566/I)



强行手玩找规律

> 尽管这很脑电波，但不可避免的有人喜欢没活硬整出构史题，出题人肯定觉得自己拉史时突发奇想得到这样的电波题老有操作了吧

[E-01矩阵_2026牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/120562/E)





### 决策问题——贪心转暴力

**考虑贪心的可行性和正确性：**

1. **缺乏最优子结构**：局部最优会严重挤压未来的决策空间。
2. **陷入无穷的 Case By Case分类讨论**：当局部贪心无法覆盖全局时，人脑就会试图去打补丁，这在算法竞赛中是**绝对的红灯警告**。

**纠偏准则**： 当你发现一个贪心策略需要分类讨论的 Case 超过 3 个，且互相之间有后效性（你现在的策略限制了未来的策略）时，**立刻停手**，回头看数据范围。数据范围小，直接转搜索或 DP。

- **贪心抉择的构造性**思维：我该怎么决策得到最优解
- **暴力查找的结构性**思维：最优解一定可以在什么情况下产出

[Problem - D - Codeforces](https://codeforces.com/contest/2188/problem/D)（遍历唯一的处理1变0的补正点）

[C-墨提斯的排列_2026牛客寒假算法基础集训营4](https://ac.nowcoder.com/acm/contest/120564/C)（翻转）

- **状态设计与转移**的动态规划思维：设计一个无后效性，具有最优子结构的状态



# 编码

> 无脑引擎驱动（Core Loop）——在这个阶段，**绝对不要再动脑思考业务逻辑**。把自己当成一个打字机，把草稿纸上推导好的方程一字不差地翻译过来。卡住往往是因为在写内部循环时，又开始怀疑边界对不对。

### 编码片段

- 拆分整个编码过程为多个编码片段，快速处理那些脑中熟悉的片段，慢慢思考那些题目特性的片段
- 锻炼编码能力的过程就是不断将题目特性变为脑中熟悉的过程



### 更好的编码方法

- bool条件的且与或

需要全部为真才为真（任意为false即为false）

```cpp
bool ok = true;
ok &= condition;
```

需要全部为假才为假（任意为true即为true）

```cpp
bool ok = false;
ok |= condition
```

- 只有在需要交换、排序或stl的时候才考虑把数据用结构体或array聚合起来，否则直接用变量名更清晰
- 函数内只引用传递的参数时，不必写成lambda函数

[G-真白的幻觉](https://ac.nowcoder.com/acm/contest/120564/G)

- 复杂的分类讨论问题，考虑先在草稿上写出**决策树**

[F - Concat (2nd)](https://atcoder.jp/contests/abc434/tasks/abc434_f)

- 必须要下标运算来表示点信息之间的关系时

```cpp
set[i] = s ^ (1 << id.size());		// 点数组存下标
id.emplace_back(cid);				// 下标数组存信息
```

- 从后往前找一个顺序周期时

```cpp
int f[12];
for(int i = 0; i < 12; i ++) {
    f[n % 12] = n;
    n --;
}
```



# 找bug与检查

- **极端样例特判**——考虑对 $0$ 和 $n$ 的特判

[B - Locked Rooms](https://atcoder.jp/contests/abc423/tasks/abc423_b)

- **越界**——注意题目数据范围在运算下是否会越界

[D - Long Waiting](https://atcoder.jp/contests/abc423/tasks/abc423_d)

- **越界**——注意代码是否访问了越界的数组

- **初始化**——注意维护值的初始设置必须是无论如何也取不到的值

[J-MST Problem_2026牛客寒假算法基础集训营1](https://ac.nowcoder.com/acm/contest/120561/J)（inf需要设置成合法值无论如何也达不到的值，最好直接默认设为inf=2e9+10）

- **取等**——关键不等式是否需要取等
- **括号与优先级**——注意符号，特别是位运算符号的优先级

[91. 解码方法 - 力扣（LeetCode）](https://leetcode.cn/problems/decode-ways/submissions/707423692/)（`||`的优先级是大于`&&`的，判断最开头放防越界条件时，需要给后面的其他(带`||`)条件打一个括号）

- **更新时机**——循环中滚动维护的变量既需要当前轮次的值，又需要上一轮次的值

[152. 乘积最大子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-product-subarray/description/)



- 滚动数组使用前需要给当前维度清零

[494. 目标和 - 力扣（LeetCode）](https://leetcode.cn/problems/target-sum/description/)



- 考虑当前思路是建立在什么基础上的，这样的基础是否会因题目条件发生改变

[C - Lock All Doors](https://atcoder.jp/contests/abc423/tasks/abc423_c)

- 对同一个变量进行多次维护时，是否保证了该变量未被修改

[E-小橙的幸运数（hard）_牛客小白月赛129](https://ac.nowcoder.com/acm/contest/128675/E)（每次二分check时不能直接修改 $x$，所以应该用一个新变量承接 $x$）



如果 `a | b`，那么：

- a是b的约数，`b mod a = 0`
- b是a的倍数，`b = a * k`
- `a ≤ |b|`（除非 b=0）





# 名词

解空间

可维护性