#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(k + 1);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        s[x % k] ++;
    }

    bool f = true;
    for(int i = 0; i < k; i ++) {
        if(s[i] % 2 == 1) {
            f = false;
            break;
        }
    }

    cout << (f ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
