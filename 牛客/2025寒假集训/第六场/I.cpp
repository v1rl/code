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
    ans[4] = {1, 2, 4, 3};
    ans[6] = {1, 2, 4, 3, 6, 5};
    ans[7] = {1, 2, 4, 7, 6, 3, 5};
    ans[8] = {1, 2, 4, 7, 8, 6, 5, 3};
    ans[9] = {1, 2, 4, 7, 6, 8, 3, 9, 5};
    ans[10] = {1, 2, 4, 7, 10, 8, 5, 6, 3, 9};
    ans[11] = {1, 2, 4, 7, 10, 8, 5, 6, 3, 11, 9};
    ans[15] = {1, 2, 4, 7, 10, 8, 5, 6, 3, 11, 9, 15, 13, 12, 14};
    ans[17] = {1, 2, 4, 7, 10, 8, 5, 6, 3, 11, 9, 15, 13, 12, 14, 17, 16};

    int fac = n / 12;
    int lst = n % 12;
    if(lst == 3 || lst == 5) {
        fac --;
        lst += 12;
    }

    for(int i = 0; i < fac; i ++) {
        for(int j = 0; j < 12; j ++) {
            cout << i * 12 + lp[j] << ' ';
        }
    }

    for(auto x : ans[lst]) {
        cout << x + 12 * fac << ' ';
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