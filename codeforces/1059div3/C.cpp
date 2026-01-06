#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
1001
0110
*/


void solve() {
    int a, b;
    cin >> a >> b;
    int mx = 0;
    for(int i = 31; i >= 0; i --) {
        if(a >> i & 1) {
            mx = (1 << (i + 1)) - 1;
            break;
        }
    }

    if(b > mx) {
        cout << -1 << '\n';
        return;
    }

    vector<int> bita(32), bitb(32);
    for(int i = 31; i >= 0; i --) {
        if(a >> i & 1) {
            bita[i] = 1;
        }
    }
    for(int i = 31; i >= 0; i --) {
        if(b >> i & 1) {
            bitb[i] = 1;
        }
    }
    
    cout << 2 << '\n';
    int res1 = 0;
    for(int i = 0; i <= 31; i ++) {
        if(bitb[i] == 1 && bita[i] == 0) {
            res1 |= (1 << i);
        }
    }
    cout << res1 << ' ';
    int res2 = 0;
    for(int i = 0; i <= 31; i ++) {
        if(bita[i] == 1 && bitb[i] == 0) {
            res2 |= (1 << i);
        }
    }
    cout << res2 << '\n';
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