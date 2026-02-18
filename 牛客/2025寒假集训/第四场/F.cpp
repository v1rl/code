#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
让纯1串尽可能少
同时让01串尽可能多
*/

const int inf = 1e9 + 10;
const int mod = 998244353;

void solve() {
    int a, b;
    cin >> a >> b;

    if(a < b) {
        int t = b / (a + 1);
        int lst = b % (a + 1);

        for(int i = 0; i < a; i ++) {
            if(lst) {
                cout << string(t + 1, '1');
                lst --;
            } else {
                cout << string(t, '1');
            }
            cout << 0;
        }
        cout << string(t, '1') << '\n';
    } else {
        int t = a / (b + 1);
        int lst = a % (b + 1);

        for(int i = 0; i < b; i ++) {
            if(lst) {
                cout << string(t + 1, '0');
                lst --;
            } else {
                cout << string(t, '0');
            }
            cout << 1;
        }
        cout << string(t, '0') << '\n';
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
