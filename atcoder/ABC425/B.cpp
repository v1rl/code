#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> bk(n + 1);
    vector<int> ans(n);
    bool f = true;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] != -1) {
            bk[a[i]] ++;
            if(bk[a[i]] > 1) {
                f = false;
            }            
        }
    }

    if(!f) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
    int cnt = 1;
    for(int i = 0; i < n; i ++) {
        while(bk[cnt]) {
            cnt ++;
        }
        if(a[i] == -1) {
            a[i] = cnt;
            cnt ++;
        }
        cout << a[i] << ' ';
    }
    cout << '\n';
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