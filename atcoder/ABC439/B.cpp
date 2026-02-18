#include<bits/stdc++.h>
using namespace std;
using i64 = long long;



void solve() {
    int x;
    cin >> x;
    vector<int> vis(2027);
    while(x != 1) {
        if(vis[x]) {
            cout << "No" << '\n';
            return;
        }
        vis[x] = true;
        string s = to_string(x);
        x = 0;
        for(auto c : s) {
            int ch = c - '0';
            x += ch * ch;
        }
    }
    cout << "Yes" << '\n';
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
