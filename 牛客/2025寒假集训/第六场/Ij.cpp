#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

vector<int> ans[18];

void solve() {
    int n;
    cin >> n;

    int lp[] = {1, 3, 9, 11, 12, 2, 7, 10, 4, 5, 8, 6};

    if(n == 3 || n == 5) {
        cout << -1 << '\n';
        return;
    }

    ans[1] = {1};
    ans[2] = {1, 2};
    ans[4] = {3, 2, 4, 1};
    ans[6] = {2, 4, 5, 6, 3, 1};
    ans[7] = {5, 2, 4, 7, 6, 3, 1};
    ans[8] = {2, 5, 4, 8, 7, 6, 3, 1};
    ans[9] = {2, 4, 5, 8, 6, 7, 3, 9, 1};
    ans[10] = {6, 2, 4, 8, 7, 10, 5, 3, 9, 1};
    ans[11] = {6, 2, 7, 4, 8, 11, 10, 5, 3, 9, 1};
    ans[15] = {6, 12, 10, 2, 4, 8, 11, 14, 7, 3, 9, 13, 15, 5, 1};
    ans[17] = {6, 12, 10, 2, 4, 11, 8, 16, 13, 14, 7, 3, 9, 17, 15, 5, 1};

    vector<int> a;
    while(n >= 24 || (n >= 12 && n != 15 && n != 17)) {
        int f[12];
        for(int i = 0; i < 12; i ++) {
            f[n % 12] = n;
            n --;
        }

        vector<int> v = {f[1], f[3], f[9], f[11], f[0], f[2], f[7], f[10], f[4], f[5], f[8], f[6]};
        a.insert(a.end(), v.begin(), v.end());
    }

    a.insert(a.end(), ans[n].begin(), ans[n].end());
    for(auto x : a) {
        cout << x << ' ';
    }
    cout << '\n';
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