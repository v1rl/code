#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

// 贪心：一直找最小和最大成对是最优
// 注意成对的处理

void solve() {
	int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for(int i = 1; i <= m; i ++) {
        cin >> a[i];
    }

    // 如果是要得到前两位呢？
    // 可以直接对x、 y做修改
    sort(a.begin() + 1, a.end(),
        [&](auto x, auto y) {
            x /= 100, y /= 100;
            return x < y;
        });

    vector<array<int, 2>> ans(n + 1);
    for(int i = 1, j = 1; i <= n; i += 2, j ++) {
        ans[i] = {a[j], a[m - j + 1]};
        // 确保i + 1没有越界
        if(i + 1 <= n) ans[i + 1] = {a[m - j + 1], a[j]};
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= 6; j ++) {
            cout << ans[i][j & 1] << " \n"[j == 6];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}