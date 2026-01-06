#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    set<int> S;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(S.count(x)) {
            continue;
        }
        S.insert(x);
    }  
    cout << S.size() << '\n';
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