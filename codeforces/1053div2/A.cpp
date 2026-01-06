#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
若右边总是左边 +1，答案为n - 最大 + 1

若右边有归一操作，答案最多为1
需要合法，同时最大值小于n，即归一前的最大值比上一个最大值大1
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for(int i = 1; i <= m; i ++) {
        cin >> a[i];
    }
    bool f = true;
    int mx = 0;
    for(int i = 1; i <= m; i ++) {
        if(i != 1 && a[i] != a[i - 1] + 1) {
            f = false;
            break;
        }
        mx = max(mx, a[i]);
    }
    if(f) {
        cout << max(0, n - mx + 1) << '\n';
        return;
    }


    int lst = -1;
    for(int i = 1; i <= m; i ++) {
        if(i != 1 && a[i] != a[i - 1] + 1) {
            if(a[i] != 1) {
                cout << 0 << '\n';
                return;
            }
            if(lst != -1 && a[i - 1] != lst + 1) {
                cout << 0 << '\n';
                return;
            }
            lst = a[i - 1];
        }
    }
    if(lst <= n) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
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
