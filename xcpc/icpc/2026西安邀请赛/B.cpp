#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
typedef pair<int, int> PII;

void solve() {
    i64 n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    s = '#' + s;

    i64 times = (x + y) / n;
    int mid = (x + y) % n;

    vector<int> numL(3), numR(3);
    for(int i = 1; i <= mid; i ++) {
        numL[s[i] - '0'] ++;
    }
    for(int i = mid + 1; i <= n; i ++) {
        numR[s[i] - '0'] ++;
    }

    int l0 = -1, r0 = -1;
    if(times == 0) {
        if(x >= numL[0] && x <= numL[0] + numL[2]) {
            l0 = x - numL[0];
            r0 = numR[2];
        } else {
            cout << -1 << '\n';
            return;
        }
    } else {
        for(int i = numL[2]; i >= 0; i --) {
            i64 lst = x - (times + 1) * (numL[0] + i);
            if(lst >= 0 && lst % times == 0) {
                int nd = lst / times;
                if(nd >= numR[0] && nd <= numR[0] + numR[2]) {
                    l0 = i;
                    r0 = nd - numR[0];
                    break;
                }
            }
        }
    }

    if(l0 == -1) {
        cout << -1 << '\n';
        return;
    }

    for(int i = 1; i <= mid; i ++) {
        if(s[i] == '2') {
            if(l0) {
                cout << 0;
                l0 --;
            } else {
                cout << 1;
            }
        } else {
            cout << s[i];
        }
    }

    for(int i = mid + 1; i <= n; i ++) {
        if(s[i] == '2') {
            if(r0) {
                cout << 0;
                r0 --;
            } else {
                cout << 1;
            }
        } else {
            cout << s[i];
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}