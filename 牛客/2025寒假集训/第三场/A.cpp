#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*

*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= 10; i ++) {
        if(n == i * (i + 1)) {
            cout << "YES" << '\n';
            return;
        }
    }    
    cout << "NO" << '\n';
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