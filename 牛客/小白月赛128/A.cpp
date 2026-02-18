#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;
const int inf = 1e9;

/*

*/

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for(auto &c : s) {
        if(c == 'O') {
            c = '0';
        }
        if(c == '1' || c == 'I') {
            c = 'l';
        }
    }

    for(auto &c : t) {
        if(c == 'O') {
            c = '0';
        }
        if(c == '1' || c == 'I') {
            c = 'l';
        }
    }

    if(s == t) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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