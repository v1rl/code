#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2e4 + 10;
const int inf = 1e9;

/*
*/

void solve() {
    int n;
    cin >> n;
    multiset<int> S;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    S.insert(a[1]);
    int cur = a[1];
    auto it = S.begin();
    cout << *it << ' ';

    for(int i = 3; i <= n; i += 2) {
        int x = a[i - 1], y = a[i];
        S.insert(x);
        S.insert(y);
        if(x > *it && y > *it) {
            it ++;
        } else if(x <= *it && y <= *it) {
            it --;
        }
        cout << *it << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --) {
        solve();
    }
    return 0;
}