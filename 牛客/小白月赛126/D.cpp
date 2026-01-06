#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
区间增变成了一个递增 / 递减排列
考虑给区间存储排列的起点
全部都是单点查询，我们没有pushdown的必要
将路径上所有区间的答案统计上即可

区间如何累计？
存储相对值，用位置-相对值累计答案
*/


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        for(int j = x - 1; j <= x + 1; j ++) {
            a[j] ++;
        }
        for(int j = max(x + 2, y - 1); j <= y + 1; j ++) {
            a[j] ++;
        }
    }

    while(q --) {
        int x;
        cin >> x;
        cout << n - a[x] << ' ';
    }
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
