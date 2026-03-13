#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int sum = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        sum ^= a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }

    int base[30] {}, set[30] {};
    vector<int> id;
    for(int i = 0; i < n; i ++) {
        int x = a[i] ^ b[i];
        int s = 0;
        for(int j = 29; j >= 0; j --) {
            if(x >> j & 1) {
                if(base[j]) {
                    x ^= base[j];
                    s ^= set[j];
                } else {
                    base[j] = x;
                    set[j] = s ^ (1 << id.size());
                    id.emplace_back(i);
                    break;
                }
            }
        }
    }

    int s = 0;
    for(int i = 29; i >= 0; i --) {
        if(sum >> i & 1) {
            sum ^= base[i];
            s ^= set[i];
        }
    }

    if(sum) {
        cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < 30; i ++) {
        if(s >> i & 1) {
            a[id[i]] = b[id[i]];
        }
    }

    for(int i = 0; i < n; i ++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
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