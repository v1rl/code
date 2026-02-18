#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int cnt = 0;
    for(int i = 2; i <= n; i ++) {
        if(a[i] == a[i - 1] || a[i] == (7 - a[i - 1])) {
            for(int j = 1; j <= 6; j ++) {
                if(j == a[i - 1] || j == 7 - a[i - 1] || (i != n && j == a[i + 1]) || (i != n && j == 7 - a[i + 1])) {
                    continue;
                }
                cnt ++;
                a[i] = j;
                break;
            }
        }
    }

    cout << cnt << '\n';
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
