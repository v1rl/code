#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
/*
关键词：均分贪心，等差数列，二分答案

被回费操作拆分的等差数列
我们得让休息次数尽可能少，等差数列次数为休息次数+1
显然，让每一轮的等差数列尽可能均匀就可以得到最优解，我们可以通过除法和取模得到这样的等差数列
二分休息次数后，只需要判断花费是否严格小于h即可

两种相邻的等差数列，全部按小的算然后加上大的贡献即可
*/

void solve() {
    int h, d;
    cin >> h >> d;
    int l = 0, r = d;

    auto check = [&](int mid) {
        int base = d / (mid + 1);
        int lth = d % (mid + 1);
        i64 cost = 1ll * base * (base + 1) / 2 * (mid + 1);
        cost += 1ll * (base + 1) * lth;
        cost -= mid;
        return cost < h;
    };

    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l + d << '\n';
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