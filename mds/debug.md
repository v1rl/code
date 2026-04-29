# debug

- **极端样例特判**——考虑对极小或极大的特判

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

- `if(condition) return true`的逻辑不要写成`return condition`

[P3413 SAC#1 - 萌数 - 洛谷](https://www.luogu.com.cn/problem/P3413)

- 大小关系是否确定

[Problem - D - Codeforces](https://codeforces.com/gym/105911/problem/D)

- 变量类型是否读错

[Problem - F - Codeforces](https://codeforces.com/gym/105911/problem/F)

- 复制粘贴时变量名未修改

- 函数传递参数与返回参数是否需要long long

- 快速幂传入的底数过大，是否相乘会爆long long

[Problem - 896C - Codeforces](https://codeforces.com/problemset/problem/896/C)

- while(不符合目标条件)-继续，看看循环的中止条件是否写反了
- 环退化为单点或双点一边

https://codeforces.com/gym/105977/C

- 多个并行if条件是否错漏

- 不同起点的树，父节点数组不可复用
- 在暴力遍历中是否遗漏对不合法数据（负数）的跳过

https://codeforces.com/gym/105977/problem/B

- 想清楚是下取整还是上取整

https://codeforces.com/gym/105977/problem/B

- 递归的特判返回不要忘了return
- 排序或其他迭代器操作时，注意是1index还是0index
- 复制粘贴时，注意是否做到了完全适配性修改
- 多维度vector需要将更小的维度放在前面
- 不当地重复定义变量导致局部顶掉了全局
- 搜索回溯后是否将对应的修改也完成了回溯