#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

// a不执行
// b、c最多执行两次
// 从左往右向a贪心
// 统计个数 
// ca \ cb \ ba \ cbba \ bcca

//aaaaaaaaaaaaaaabbbabcbabbbbabc
//aaaaaaaaaaaaaaabbbabcbabbbbabc


void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    bool lstcb = false, lstbc = false;
    int ca = 0, cb = 0, ba = 0, cbba = 0, bcca = 0;

    for(int i = 1; i <= m; i ++) {
        char x, y;
        cin >> x >> y;
        if(x == 'c' && y == 'a') {
            ca ++;
            if(lstbc) {
                lstbc = false;
                bcca ++;
            }
        } else if(x == 'c' && y == 'b') {
            cb ++;
            lstcb = true;
        } else if(x == 'b' && y == 'a') {
            ba ++;
            if(lstcb) {
                lstcb = false;
                cbba ++;
            }
        } else if(x == 'b' && y == 'c') {
            lstbc = true;
        }
    }

    for(int i = 0; i < n; i ++) {
        if(s[i] == 'b') {
            if(ba) {
                s[i] = 'a';
                ba --;
                // cbba = min(ba, cbba);
            } else if(bcca && ca) {
                s[i] = 'a';
                bcca --;
                // bc --;
                ca --;
            } 
        } else if(s[i] == 'c') {
            if(ca) {
                s[i] = 'a';
                ca --;
                // bcca = min(bcca, ca);
            } else if(cbba && cb && ba) {
                s[i] = 'a';
                cbba --;
                cb --;
                ba --;
            } else if(cb) {
                s[i] = 'b';
                cb --;
                // cbba = min(cb, cbba);
            }
        }
    }

    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}