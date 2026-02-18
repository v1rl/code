#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
显然，状态会影响后续的选择空间，无法用简单的乘法原理
注意题目的特殊数据范围，考虑记录当前状态的状压dp
题目变换过程中相对位置不变，题目的状态都是子序列，符合状压dp对每个点分设0和1
转移过程就是某一位从0变1的过程
注意到：连续相等的0变1从得到的子序列结果是一致的，发生了重复
所以，只考虑与上一位有效位(1)字符不同的有效位(1)发生转移

f[i的所有bit1位形成的字符串]的字符串序列种类数
*/

const int mod = 998244353;

void solve() {
    int n;
    string t;
    cin >> n >> t;
    vector<int> f(1 << n, 0);
    f[0] = 1;
    for(int i = 1; i < (1 << n); i ++) {
        char lst = 0;
        for(int j = 0; j < n; j ++) {
            if((i >> j) & 1) {
                if(t[j] != lst) {
                    f[i] = (f[i] + f[i ^ (1 << j)]) % mod;
                }
                lst = t[j];
            }
        }
    }
    cout << f[(1 << n) - 1] << '\n';
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