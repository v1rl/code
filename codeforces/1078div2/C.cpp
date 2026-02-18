#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> mask(n);
    for(int i = 0; i < m; i ++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j ++) {
            mask[j] |= 1 << (s[j] - 'a');
        }
    }

    for(int d = 1; d <= n; d ++) {
        if(n % d == 0) {
            bool f1 = true;
            string ans;

            for(int i = 0; i < d; i ++) {
                bool f2 = false;

                for(int k = 0; k < 26; k ++) {
                    bool f3 = true;

                    for(int j = i; j < n; j += d) {
                        f3 &= (mask[j] >> k & 1);
                    }

                    if(f3) {
                        f2 = true;
                        ans += 'a' + k;
                        break;
                    }
                }

                if(!f2) {
                    f1 = false;
                    break;
                }
            }

            if(!f1) {
                continue;
            }
            
            for(int i = 0; i < n / d; i ++) {
                cout << ans;
            }
            cout << '\n';
            break;
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