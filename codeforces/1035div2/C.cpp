#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

// 奇数情况下，xor同一个数会得到本身，and也会得到本身
// 偶数情况下，xor同一个数会得到0，考虑通过修改偶数个数让and也得到0
// 一定范围内找两个and起来为0的数，考虑二进制下是否发生最大位的进位

void solve()
{
    i64 n, l, r, k;
    cin >> n >> l >> r >> k;
    if(n & 1) {
        cout << l << '\n';
        return;
    } else {
        i64 p1 = 1, p2 = 1;
        while(p1 * 2 <= l) {
            p1 *= 2;
        }
        while(p2 * 2 <= r) {
            p2 *= 2;
        }
        if(p1 == p2 || n == 2) {
            cout << -1 << '\n';
            return;
        }
        else {
            if(k <= n - 2) {
                cout << l << '\n';
            } else {
                cout << p1 * 2 << '\n';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}