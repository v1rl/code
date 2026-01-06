#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
48 100 99
48 50 49
51 50 52

不难发现48既可以得到50，又可以得到52
这也就代表着，当你有一个连续数的时候，你可以通过它将任意其他数+2/-2

两组连续数对应，其余数中两组奇数偶数个数一致，则满足条件
进一步地，两组数奇数偶数个数一致，且都存在连续数，则满足条件
另外，需要特判以下完全一致的情况
*/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    int o1 = 0, e1 = 0;
    int o2 = 0, e2 = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool f1 = 0, f2 = 0;
    bool f = true;
    for(int i = 0; i < n; i ++) {
        if(a[i] != b[i]) {
            f = false;
            break;
        }
    }
    if(f) {
        cout << "Yes" << '\n';
        return;
    }
    for(int i = 0; i < n; i ++) {
        if(a[i] & 1) {
            o1 ++;
        } else {
            e1 ++;
        }
        if(i > 0 && a[i] == a[i - 1] + 1) {
            f1 = true;
        }
        if(b[i] & 1) {
            o2 ++;
        } else {
            e2 ++;
        }
        if(i > 0 && b[i] == b[i - 1] + 1) {
            f2 = true;
        }
    }

    if(f1 && f2 && o1 == o2 && e1 == e2) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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