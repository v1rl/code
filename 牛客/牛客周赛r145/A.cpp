#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
typedef pair<int, int> PII;

void solve() {
    string s;
    cin >> s;
    set<char> S;
    for(auto c : s) {
        S.insert(c);
    }

    if(S.size() == 2) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
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