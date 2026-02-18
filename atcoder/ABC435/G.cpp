#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
约束条件：颜色有范围；格子i的前后格子中有且仅有一个与之同色
注意到：相邻格子有且仅有一个同色，则颜色的排布形式必然为恰好两个连续格子同色
不妨称两个连续格子为“骨牌”，任意颜色都只能以骨牌的形式出现，同色的骨牌不能连续出现
这样的"不能连续出现"类型约束，不难联想到可以用dp处理
我们设dp[i][c]表示只考虑前i个格子，以(i-1,i)颜色为c的骨牌结尾的合法方案数
可以得到一个显然的转移方程：dp[i][c] = sum(dp[i - 2][!=c])
设S[i]为只考虑前i个格子的所有合法情况数，我们可以通过维护S[i]优化对!=c的所有颜色的枚举，得到dp[i][c] = S[i - 2] - dp[i - 2][c]
但此时仍然需要枚举区间支持的颜色集，于是我们思考是否存在直接维护颜色集总和(不包括无色)的做法
维护集合过程中，需要在完成"对每一个元素执行raw=S-raw"，"添加元素"，"删除元素"的操作的情况下维护总和
更本质地说，就是全体修改与查询和单点插入与查询
注意到修改多而查询少的性质，不难联想到懒标记数据结构
考虑到：维护懒标记的前提是标记必须要具有封闭性，即两个操作叠加后，仍然是同一种类型的操作
注意到：每次修改都是raw=S-raw，这是一个k=-1，b=S的仿射变换，支持用懒标记维护
这样，我们就通过维护懒标记数据结构优化了对颜色集的枚举
因为每次dp转换的跨度为2，我们需要分奇偶维护这样的懒标记数据结构
另外，因为不染色也是合法的可能，所以S的转移还要考虑不染色情况下继承S[i - 1]
从而得到转移方程为：S[i] = S[i - 1] + dp[i][c]
*/

const int mod = 998244353;

struct Info {
    int sum = 0;
    int add = 0;
    int mul = 1;
    int cnt = 0;
    vector<int> raws;

    Info(int n) {
        raws.assign(n + 1, 0);
    };

    void apply(int s) {
        sum = (1ll * s * cnt % mod - sum) % mod;
        mul *= -1;
        add = (s - add) % mod;
    }

    // mul * raw + add = val
    void addc(int id, int val) {
        // 此处根据公式反推出raw
        int raw = 1ll * (val - add) * mul % mod;
        raws[id] = raw;
        sum += val;
        sum %= mod;
        cnt ++;
    }

    void rem(int id) {
        int val = (1ll * mul * raws[id] % mod + add) % mod;
        sum -= val;
        sum %= mod;
        cnt --;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adds(n + 1), rems(n + 1);
    for(int i = 1; i <= m; i ++) {
        int l, r;
        cin >> l >> r;
        l ++;

        if(l > r) {
            continue;
        }
        // 用长度为2的循环将奇数和偶数的情况各自绑定在一起处理，避免出现错误信息
        for(int k = 0; k < 2; k ++) {
            int L = l, R = r;
            if(L % 2 != k) {
                L ++;
            }
            if(L > R) {
                continue;
            }
            adds[L].emplace_back(i);

            if(R % 2 != k) {
                R --;
            }
            if(R + 2 <= n) {
                rems[R + 2].emplace_back(i);
            }
        }
    }


    vector<int> sum(n + 1);
    array<Info, 2> dp = {Info(m), Info(m)};
    sum[0] = sum[1] = 1;
    for(int i = 2; i <= n; i ++) {
        int prev = sum[i - 2];
        int cur = i % 2;
        dp[cur].apply(prev);
        for(auto id : adds[i]) {
            dp[cur].addc(id, prev);
        }
        for(auto id : rems[i]) {
            dp[cur].rem(id);
        }
        sum[i] = (sum[i - 1] + dp[cur].sum) % mod;
    }

    cout << (sum[n] + mod) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
