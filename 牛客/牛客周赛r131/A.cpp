#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
(()())
*/

const int mod = 998244353;

vector s{"red","orange","blue","green"};
void solve() {
    char n;
    cin >> n;
    cout << s[n - 'A'];
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
