#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
    std::string s[7] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};
    int mx = -1, mid = -1;
    for(int i = 0; i < 7; i ++) {
        int x;
        cin >> x;
        if(x > mx) {
            mx = x;
            mid = i;
        }
    }

    cout << s[mid] << '\n';
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
