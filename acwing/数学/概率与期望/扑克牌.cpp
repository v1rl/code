#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
constexpr int N = 14;
constexpr double inf = 1e9;
double f[N][N][N][N][5][5];

// https://www.acwing.com/problem/content/description/220/

/*
本题数据范围不大，同时约束条件又比较多，我们要求的是满足约束条件的期望
不是暴力就是dp，暴力时间复杂度上过不去，自然地往dp方向上靠
考虑 
显然这里使用后者更好，将当前状态还需要抽牌次数期望作为属性

Trick：多个维度同时转移，执行抽牌时每个维度都会发生变化，显然这不是正向线性dp能解决的，我们考虑记忆化搜索
Trick：当前状态的期望是所有可能发生的 概率 * 发生此概率后的期望 的累加，发生此概率后的期望一般为发生此概率后状态的期望加上一个数
*/
  
int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    memset(f, -1, sizeof f);

    function<double(int, int, int, int, int, int)> dp = [&](int a, int b, int c, int d, int x, int y) {
        double &v = f[a][b][c][d][x][y];
        if(v >= 0) return v;
        int sa = a + (x == 1) + (y == 1);
        int sb = b + (x == 2) + (y == 2);
        int sc = c + (x == 3) + (y == 3);
        int sd = d + (x == 4) + (y == 4);

        if(sa >= A && sb >= B && sc >= C && sd >= D) return v = 0;

        int sum = 54 - a - b - c - d - (x != 0) - (y != 0);
        if(sum == 0) return v = inf;

        v = 0;
        if(a < 13) v += (13.0 - a) / sum * (dp(a + 1, b, c, d, x, y) + 1);
        if(b < 13) v += (13.0 - b) / sum * (dp(a, b + 1, c, d, x, y) + 1);
        if(c < 13) v += (13.0 - c) / sum * (dp(a, b, c + 1, d, x, y) + 1);
        if(d < 13) v += (13.0 - d) / sum * (dp(a, b, c, d + 1, x, y) + 1);
        if(x == 0) {
            double t = inf;
            for(int i = 1; i <= 4; i ++) {
                t = min(t, 1.0 / sum * (dp(a, b, c, d, i, y) + 1));
            }
            v += t;
        }
        if(y == 0) {
            double t = inf;
            for(int i = 1; i <= 4; i ++)
                t = min(t, 1.0 / sum * (dp(a, b, c, d, x, i) + 1));
            v += t;
        }
        return v;
    };

    double ans = dp(0, 0, 0, 0, 0, 0);
    if(ans >= inf) ans = -1;
    printf("%.3lf", ans);
}  