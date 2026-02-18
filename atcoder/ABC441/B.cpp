#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    vector<int> a(26), b(26);
    int n, m;
    cin >> n >> m;
    string sa, sb;
    cin >> sa >> sb;
    for(auto c : sa) {
        a[c - 'a'] = true;
    }
    for(auto c : sb) {
        b[c - 'a'] = true;
    }
    int q;
    cin >> q;
    while(q --) {
        string s;
        cin >> s;
        bool fa = true, fb= true;
        for(auto c : s) {
            if(!a[c - 'a']) {
                fa = false;
            }
            if(!b[c - 'a']) {
                fb = false;
            }
        }
        if(fa && !fb) {
            cout << "Takahashi" << '\n';
        } else if(!fa && fb) {
            cout << "Aoki" << '\n';
        } else {
            cout << "Unknown" << '\n';
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}