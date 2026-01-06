#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const int inf = 1e9;

void solve() {

    vector<string> p;
    p.emplace_back("Ocelot");
    p.emplace_back("Serval");
    p.emplace_back("Lynx");
    
    string s, t;
    cin >> s >> t;
    int a, b;
    for(int i = 0; i < 3; i ++) {
        if(p[i] == s) {
            a = i;
        }
        if(p[i] == t) {
            b = i;
        }
    }
    if(a >= b) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
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