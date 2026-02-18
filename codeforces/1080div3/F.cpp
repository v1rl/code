#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> v(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    } 

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(j == i) {
                continue;
            }
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
