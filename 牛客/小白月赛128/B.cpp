#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;
const int inf = 1e9;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    auto divide = [&](int x) {  
        if(x == 1) {
            return true;
        }
        int cnt = 0;      
        for(int i = 2; i <= x / i; i ++) {
            if(x % i == 0) {
                cnt ++;
                while(x % i == 0) {
                    x /= i;
                }
            }
        }
        if(x > 1) {
            cnt ++;
        }
        return cnt == 1;
    };

    for(int i = 0; i < n; i ++) {
        if(divide(a[i])) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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