#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*

*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater());
    sort(b.begin(), b.end(), greater());

    i64 sa = accumulate(a.begin(), a.end(), 0ll);
    i64 sb = accumulate(b.begin(), b.end(), 0ll);
    if(sa == sb) {
        cout << 1 << '\n';
    } else if(sa > sb) {
        for(int i = 0; i < n; i ++) {
            sa -= a[i];
            if(sa <= sb) {
                cout << i + 1 << '\n';
                break;
            }
        }
    } else {
        for(int i = 0; i < m; i ++) {
            sb -= b[i];
            if(sb <= sa) {
                cout << i + 1 << '\n';
                break;
            }
        }
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