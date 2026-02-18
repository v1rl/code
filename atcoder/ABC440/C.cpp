#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
将长度为n的序列拆分成多个大小为2*w的环（最后一个可能不足2*w），然后从环中选取连续的w个数
注意到：每次选取的连续w个数，它们mod(2*w)后的得到的下标集合是相同的
将原数组分为多个大小为2*w的块，遍历所有块并固定一个开头，取其中连续的长度为w的子串
之后，根据差量法得到不同的长度为w的子串产生的贡献，并取最小的为答案
*/

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> c(n + 2);
    c[0] = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }

    i64 res = 0;
    for(int l = 0; l <= n; l += 2 * w) {
        for(int i = l; i < min(n + 1, l + w); i ++) {
            res += c[i];
        }
    }

    i64 ans = res;
    // 正常来说只需要到执行2*w-1次，但因为是不断循环，直接执行2*w次也无所谓
    for(int x = 0; x < 2 * w; x ++) {
        for(int l = 0; l <= n; l += 2 * w) {
            res -= c[min(n + 1, l + x)];
            // 需要注意，我们取的串是一个循环串，大于等于2*w的部分通过取模回到开头
            res += c[min(n + 1, l + (w + x) % (2 * w))];
        }
        ans = min(ans, res);
    }

    cout << ans << '\n';

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
