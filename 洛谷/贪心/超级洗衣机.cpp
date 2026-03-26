#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/super-washing-machines/description/

/*
1 2 3 4 5

a[i + 1] - (x - a[i])
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
    }

    if(sum % n) {
        cout << -1 << '\n';
        return;
    }
    sum /= n;

    vector<int> ans(n);
    for(int i = 1; i < n; i ++) {
        if(sum > a[i - 1]) {
            ans[i] += sum - a[i - 1];
        } else {
            ans[i - 1] += a[i - 1] - sum;
        }
        a[i] -= (sum - a[i - 1]);
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}