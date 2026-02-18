#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

void solve() {
    vector g(3, vector(3, 0));
    int sum = 0;
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++) {
            cin >> g[i][j];
            sum |= (1 << (g[i][j] - 1));
        }
    }

    int res = -1;
    bool f = true;

    for(int i = 0; i < 3; i ++) {
        int c = 0;
        for(int j = 0; j < 3; j ++) {
            c += g[i][j];
        }
        if(res != -1 && c != res) {
            f = false;
        }
        res = c;
    }

    for(int i = 0; i < 3; i ++) {
        int c = 0;
        for(int j = 0; j < 3; j ++) {
            c += g[j][i];
        }
        if(c != res) {
            f = false;
        }
    }
    
    if(g[1][1] + g[0][0] + g[2][2] != res) {
        f = false;
    }
    if(g[1][1] + g[0][2] + g[2][0] != res) {
        f = false;
    }


    if(sum == (1 << 9) - 1 && f) {
        cout << "Yes" << '\n';
    }  else {
        cout << "No" << '\n';
    }
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
