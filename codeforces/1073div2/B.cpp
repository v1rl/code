#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> num(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        num[a[i]] ++;
    }

    if(num[0] == 0 || (num[0] > 1 && num[1] == 0)) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
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

