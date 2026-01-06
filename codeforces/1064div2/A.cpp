#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/


const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char t = s[n - 1];
    int cnt = 0;
    for(auto c : s) {
        if(c == t) {
            cnt ++;
        }
    }
    cout << n - cnt << '\n';
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
