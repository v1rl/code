#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> st(26);
    for(auto c : s) {
        st[c - 'a'] ++;
    }
    vector<int> nst(26);
    for(auto c : t) {
        nst[c - 'a'] ++;
    }
    for(int i = 0; i < 26; i ++) {
        if(st[i] != nst[i]) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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