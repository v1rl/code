#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

void solve() {
    string s = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";

    int cur = 0;
    for(auto c : s) {
        if(c == '0') {
            cur = (-cur + 7) % 4;
        } else if(c == '1') {
            cur = (-cur + 4) % 4;
        } else if(c == '2') {
            cur = (-cur + 5) % 4;
        } else if(c == '3') {
            cur = (-cur + 6) % 4;
        } else if(c == '4') {
            cur = (cur + 1) % 4;
        } else if(c == '5') {
            cur = (cur + 3) % 4;
        }
        cout << cur;
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
