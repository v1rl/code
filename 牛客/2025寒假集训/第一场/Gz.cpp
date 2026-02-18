#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

void solve() {
    string l, r;
    cin >> l >> r;
    i64 nl = stoll(l), nr = stoll(r);
    string U = "1" + string(r.size() - 1, '0');
    if(r == U) {
        if(l == r) {
            cout << 1 << '\n';
        } else {
            cout << stoll(U) - 1 << '\n';
        }
        return;
    }
    if(l.size() < r.size()) {
        l = U;
        l.back() = '1';
    }

    int k = -1;
    for(int i = 0; i < l.size(); i ++) {
        if(l[i] != r[i]) {
            k = i;
            break;
        }
    }

    if(k == -1) {
        string ans = l;
        while(ans.size() && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    } else {
        string ans;
        bool ok = true;
        for(int i = k + 1; i < l.size(); i ++) {
            ans += '9';
            ok &= (r[i] == '9');
        }
        ans += r[k] - !ok;
        for(int i = k - 1; i >= 0; i --) {
            ans += l[i];
        }
        cout << ans << '\n';
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