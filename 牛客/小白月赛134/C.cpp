#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    int S = 0;
    for(int i = n - 1; i >= 0; i --) {
        if(a[i] >= a[i + 1]) {
            S = i;
        } else {
            break;
        }
    }

    i64 ans = a[S];
    int lst = a[S];
    for(int i = S + 1; i < S + n; i ++) {
        if(a[i] > lst) {
            ans += a[i];
        }
        lst = a[i];
    }
    cout << ans << '\n';
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
