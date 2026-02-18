#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

void solve() {
    string s = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";

    int d = 0;
    for (auto c : s) {
        if (c == '0') {
            d ^= 3;
        } else if (c == '1') {
            d ^= (d & 1) << 1;
        } else if (c == '2') {
            d ^= 1;
        } else if (c == '3') {
            d ^= !(d & 1) << 1;
        } else if (c == '4') {
            d = (d + 1) % 4;
        } else {
            d = (d + 3) % 4;
        }
        cout << d;
    }
    cout << '\n';
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
