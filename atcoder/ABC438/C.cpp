#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> stk;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(stk.size() >= 3) {
            bool f = true;
            int m = stk.size();
            for(int j = 1; j <= 3; j ++) {
                if(stk[m - j] != x) {
                    f = false;
                    break;
                }
            }
            if(f) {
                for(int j = 0; j < 3; j ++) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(x);
            }
        } else {
            stk.push_back(x);
        }
    }  
    cout << stk.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
