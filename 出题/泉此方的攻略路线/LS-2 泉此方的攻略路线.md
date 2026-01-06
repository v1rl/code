LS-2	泉此方的攻略路线

泉此方最近在玩一款名为《A–MDM》的游戏。

这天，她接受了一个奖励丰富的挑战 —— ”利用 $m$ 的初始魔力攻略最多的关卡”，其设定如下：

挑战地图中共有编号为 $1, 2, 3...n$ 的 $n$ 个关卡，地图上有且仅有一条 $1$→$2$→$3$→...→$n$ 的**单向**路径。

玩家从 $1$ 号关卡出发，行进完 $n$ 号关卡后，游戏结束并开始结算。

对于行进期间经过的每一个关卡，玩家可以执行以下两项操作中的一项：

**攻略**——攻略该关卡并触发关卡的战斗。在战斗中，角色可以通过来战斗积攒魔力，同时也需要消耗魔力来击败关卡中的小怪。
若关卡结算时魔力值不小于 $0$，则攻略关卡数 $+1$ 并前往下一关卡，反之则游戏直接结束。

**跳过**——什么也不会发生，跳过该关卡并直接前往下一关卡。

最后，角色的魔力储存上限为 $l$ 。关卡结算时，超过上限的魔力自动溢出，无法储存。

作为一个游戏高手，此方很轻松地算出了各个关卡结算时的魔力变化量 $a_i$。

只怨那命运之不公，让她年纪轻轻就身患 “看到数学公式就犯困” 的绝症，这使她不得不放弃了进一步的计算。

但她并不担心，她相信你会帮她的！



第一行输入三个正整数 $n$, $m$, $l$ $(1 \leq n \leq 1000, 1 \leq m \leq l \leq 100)$ ，依次为关卡总数，初始魔力和魔力上限。

第二行输入 $n$ 个整数 $a_1, a_2...a_n$ $(-100 \leq a \leq 100) $ ，依次为关卡 $1 - n$ 结算时的魔力变化量。



第一行输出一个正整数 $b$ ，表示最多能攻略的关卡数量。

第二行输出空格隔开的 $b$ 个数，按照路径先后顺序，依次输出执行“攻略”操作的关卡的编号，表示最优攻略路线。



8 2 5
-1 -1 -1 10 -4 -2 -3 -1



5
1 2 4 6 7



本题测评方式为**Special Judge**，最优攻略路线可能有多种，你只需要输出其中一种。



```cpp
#include <bits/stdc++.h>
#define AC 0
#define WA 1
#define ERROR -1
using namespace std;

int spj(FILE *f_in, FILE *f_user)
{
    int n, m, l;
    fscanf(f_in,"%d%d%d",&n, &m, &l);
    vector<int> v(n + 1);
    vector<int> us_ans(n);
    for(int i = 1; i <= n; i ++) fscanf(f_in, "%d", &v[i]);
    vector<vector<int>> f(n + 1, vector<int>(1001, -1e9));
    for(int i = 0; i <= m; i ++) f[0][i] = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j <= l; j ++)
        {
            f[i][j] = max(f[i - 1][j], f[i - 1][max(0, j - v[i])] + 1);
        }
    }

    int ac_num = f[n][0];
    int us_num;
    fscanf(f_user, "%d", &us_num);
    for(int i = 0; i < us_num; i ++) fscanf(f_user, "%d", &us_ans[i]);

    if(us_num != ac_num) return WA;
    for(int i = 0; i < us_num; i ++)
    {
        if(i && us_ans[i] <= us_ans[i - 1]) return WA;
        if(us_ans[i] <= 0 && us_ans[i] > n) return WA;
        m = min(m + v[us_ans[i]], l);
        if(m < 0) return WA;
    }
    return AC;
}

void close_file(FILE *f)
{
    if(f != NULL){
        fclose(f);
    }
}

int main(int argc, char *args[]){
    FILE *input = NULL, *user_output = NULL;
    int result;
    if(argc != 3){
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }
    input = fopen(args[1], "r");
    user_output = fopen(args[2], "r");
    if(input == NULL || user_output == NULL){
        printf("Failed to open output file\n");
        close_file(input);
        close_file(user_output);
        return ERROR;
    }

    result = spj(input, user_output);
    printf("result: %d\n", result);
    
    close_file(input);
    close_file(user_output);
    return result;
}
```

