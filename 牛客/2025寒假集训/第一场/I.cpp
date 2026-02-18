#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*

*/

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for(int i = 29; i >= 0; i --) {
        if((l & r) >> i & 1) {
            break;
        }
        if((l ^ r) >> i & 1) {
            ans = r - (1 << i) + 1;

            for(int j = i - 1; j >= 0; j --) {
                if(~l >> j & 1) {
                    if(ans >= (l >> j << j)) {
                        ans = 1 << i;
                    }
                    break;
                }
            }
            break;
        }
    }

    if(ans >= l) {
        ans = r + 1;
    }

    cout << ans << '\n';
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