#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
typedef pair<int, int> PII;
const int inf = 1e18;

void solve() {
    vector<int> a = {1, 2, 3};
    int pos = lower_bound(a.begin(), a.end(), 3) - a.begin();
    cout << pos << '\n';
}


signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}