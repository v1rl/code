#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;

/*
*/

const i64 inf = 1e18 + 10;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    if(((sx + sy) & 1) == ((ex + ey) & 1)) {
        cout << -1 << '\n';
        return;
    }

    bool f = false;
    if(sy > ey) {
        swap(sx, ex);
        swap(sy, ey);
        f = true;
    }

    string ans;
    ans += string(sy - 1, 'L');
    ans += sx == 1 ? 'D' : 'U';
    ans += string(sy - 1, 'R');

    int y = sy;
    int op = (sx == 1);
    while(y + 1 < ey) {
        if(op) {
            ans += "RU";
        } else {
            ans += "RD";
        }
        op ^= 1;
        y ++;
    }

    ans += string(n - ey + 1, 'R');
    ans += ex == 1 ? 'U' : 'D';
    ans += string(n - ey, 'L');

    if(!f) {
        cout << ans << '\n';
    } else {
        reverse(ans.begin(), ans.end());
        for(auto c : ans) {
            if(c == 'U') {
                cout << 'D';
            } else if(c == 'D') {
                cout << 'U';
            } else if(c == 'L') {
                cout << 'R';
            } else {
                cout << 'L';
            }
        }
        cout << '\n';
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
