#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

// 将数学关系向最值转换
// 最小数大于等于最大数/2(下取整)
// 将任意其他数最多变成最小数*2+1

void solve() {
	int x;
    cin >> x;
    int cnt = 0;
    while(x) {
        x /= 2;
        cnt ++;
    }
    cout << cnt * 2 + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}