#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    vector<array<int, 32>> b(3);
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 32; j ++) {
            b[i][j] = (a[i] >> j) & 1;
        }
    }

    for(int i = 0; i < 32; i ++) {
        int num = 0;
        for(int j = 0; j < 3; j ++) {
            if(b[j][i] == 1) {
                num ++;
            }
        }
        if(num == 2) {
            cout << "NO" << '\n';
            return;
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