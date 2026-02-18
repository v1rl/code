#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 10;

void solve() {
    int a, b;
    i64 c;
    cin >> a >> b >> c;

    int lst = c % (a + b);
    if(lst >= 1 && lst <= a) {
        cout << 0;
    } else {
        cout << 1;
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