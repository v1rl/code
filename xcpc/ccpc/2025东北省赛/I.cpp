#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, stt, edd;
    cin >> n >> stt >> edd;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    if(stt == edd) {
        cout << "Yes" << '\n';
        return;
    }
    if(stt > edd) {
        swap(stt, edd);
    }
    if(stt <= n && a[stt] == edd) {
        cout << "No" << '\n';
        return;
    } 

    bool same = (stt <= n) == (edd <= n);
    if(!same) {
        cout << "Yes" << '\n';
    } else {
        if(n >= 3) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
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
