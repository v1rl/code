#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = true;
    int cnt = 0;
    for(auto c : s) {
        if(c == '1') {
            cnt ++;
        } else {
            if(cnt) {
                ok &= (cnt > 1);
                cnt = 0;                
            }
        }
    }
    if(cnt) {
        ok &= (cnt > 1);
        cnt = 0;                
    }

    cout << (ok ? "YES" : "NO") << '\n';
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
