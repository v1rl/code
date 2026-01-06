#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(x == 3 || x == 6) {
            cout << "koishiYun" << '\n';
        } else {
            cout << "Kato_Shoko" << '\n';
        }
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