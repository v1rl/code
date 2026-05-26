#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    i64 sum = 1ll * n * (n + 1) / 2;
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(i != 0 && s[i] != s[i - 1]) {
            sum -= 1ll * cnt * (cnt + 1) / 2;
            cnt = 1;
        } else {
            cnt ++;
        }
    }

    sum -= 1ll * cnt * (cnt + 1) / 2;
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}