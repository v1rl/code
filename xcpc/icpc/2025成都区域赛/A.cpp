#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
总和必须要大于100
每个非0数最多只能减去1，计个数为m
所以总和必须要小于100 + m / 2
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans(n);
    vector<int> ans2(n);
    int sum = 0;
    int m = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        ans[i] = a[i] * 10;
        ans2[i] = a[i] * 10000000;
        if(a[i] > 0) {
            m ++;
        }
        sum += a[i];
    }
    if(sum >= 100 && sum <= 100 + m / 2) {
        int bg = sum - 100;
        bg *= 2;
        for(int i = 0; i < n; i ++) {
            if(ans[i] == 0) {
                continue;
            }
            if(bg > 0) {
                ans[i] -= 5;
                bg --;
            }
        }
        cout << "Yes" << '\n';
        for(auto c : ans) {
            cout << c << ' ';
        }
        cout << '\n';
    } else if(sum < 100 && sum >= 100 - (n - 1) / 2) {
        i64 s = 0;
        int sm = 100 - sum;
        int bg = sm + 1;
        int d = 5000000;
        int dd = (1ll * 5000000 * sm) / bg + 2;
        for(int i = 0; i < n; i ++) {
            if(sm > 0) {
                ans2[i] += d - 1;
                sm --;
            } else if(bg > 0) {
                ans2[i] += dd;
                bg --;
            }
            s += ans2[i];
        }
        cout << "Yes" << '\n';
        for(auto c : ans2) {
            cout << c << ' ';
        }
        cout << '\n';
    } else {
        cout << "No" << '\n';
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