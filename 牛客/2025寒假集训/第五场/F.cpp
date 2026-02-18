#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
为了处理尾部的余数，通常需要留出至少一个周期长度给 DP 进行“调整”
最优解可能需要“从前面那堆 56 里挪出一点长度”来让尾巴的组合更赚
*/

const int mod = 1e9 + 7;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int m = n % 56;
    if(n >= 56) {
        m += 56;
    }

    i64 lst = n - m;

    i64 ans = max({lst / 2 * b, lst / 7 * a, lst / 8 * (a + b)});

    vector<i64> f(m + 1);
    vector<int> v{2, 7, 8};
    vector<int> w{b, a, a + b};

    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j <= m; j ++) {
            if(j >= v[i]) {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
    }

    cout << ans + f[m] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
