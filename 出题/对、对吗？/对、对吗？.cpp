#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    i64 l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    i64 mxadd = r1 + r2;
    i64 mxmul = max({r1 * r2, l1 * r2, r1 * l2, l1 * l2});
    i64 mxsub = max(r1 - l2, r2 - l1);

    i64 mnadd = l1 + l2;
    i64 mnmul = min({r1 * r2, l1 * r2, r1 * l2, l1 * l2});
    i64 mnsub = min(l1 - r2, l2 - r1);

    cout << mxadd << ' ' << mnadd << '\n';
    cout << mxsub << ' ' << mnsub << '\n';
    cout << mxmul << ' ' << mnmul << '\n';
}