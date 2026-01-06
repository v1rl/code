#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    string a, b;
    cin >> a >> b;
    istringstream is(a);

    int x, y;
    is >> x;
    int f = 0;
    if(a.back() == '+') {
        char c;
        is >> c;
        f += 1;
    }

    is.clear();
    is.str(b);
    is >> y;
    if(b.back() == '+') {
        char c;
        is >> c;
        f += 2;
    }

    if(x != y) {
        cout << (x > y ? "Yes" : "No") << '\n';
    } else {
        cout << (f == 1 ? "Yes" : "No") << '\n';
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
