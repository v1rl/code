#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

10101011
0000111
*/


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '0') {
            ans.emplace_back(i + 1);
        }
    }

    cout << ans.size() << '\n';
    for(auto c : ans) {
        cout << c << ' ';
    }
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