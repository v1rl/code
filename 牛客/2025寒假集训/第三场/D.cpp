#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;

bool checkCorner(char a, char b, char c) {
    return a != '0' && b != '0' && b == c;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i ++) {
        cin >> g[i];
    }

    if(checkCorner(g[0][0], g[0][1], g[1][0])) {
        cout << "NO" << '\n';
        return;
    }
    if(checkCorner(g[0][m - 1], g[0][m - 2], g[1][m - 1])) {
        cout << "NO" << '\n';
        return;
    }
    if(checkCorner(g[n - 1][m - 1], g[n - 1][m - 2], g[n - 2][m - 1])) {
        cout << "NO" << '\n';
        return;
    }
    if(checkCorner(g[n - 1][0], g[n - 1][1], g[n - 2][0])) {
        cout << "NO" << '\n';
        return;
    }

    vector<int> s;
    for(int j = 0; j < m - 1; j ++) {
        if(g[0][j] != '0') {
            s.emplace_back(g[0][j]);
        }
    }

    for(int i = 0; i < n - 1; i ++) {
        if(g[i][m - 1] != '0') {
            s.emplace_back(g[i][m - 1]);
        }
    }

    for(int j = m - 1; j > 0; j --) {
        if(g[n - 1][j] != '0') {
            s.emplace_back(g[n - 1][j]);
        }
    }

    for(int i = n - 1; i > 0; i --) {
        if(g[i][0] != '0') {
            s.emplace_back(g[i][0]);
        }
    }

    if(s.size() == 4 && s[0] == s[2]) {
        cout << "NO" << '\n';
        return;
    }

    for(int i = 1; i < n; i ++) {
        for(int j = 1; j < m; j ++) {
            if(g[i][j] != '0' && g[i - 1][j] != '0' && g[i][j] == g[i - 1][j - 1] && g[i - 1][j] == g[i][j - 1]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
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