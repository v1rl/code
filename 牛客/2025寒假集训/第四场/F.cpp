#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

void solve() {
    int a, b;
    cin >> a >> b;
    char ca = '0', cb = '1';
    if(a < b) {
        swap(a, b);
        swap(ca, cb);
    }

    int cnt = a / (b + 1);
    int lst = a % (b + 1);
    for(int i = 0; i < b; i ++) {
        if(lst) {
            cout << string(cnt + 1, ca);
            lst --;
        } else {
            cout << string(cnt, ca);
        }
        cout << cb;
    }
    cout << string(cnt, ca);
    cout << '\n';
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
