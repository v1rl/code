#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
有奇数有偶数，排序输出
只有偶数/奇数，直接输出
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool even = false, odd = false;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] & 1) {
            even = true;
        } else {
            odd = true;
        }
    }
    if(even && odd) {
        sort(a.begin(), a.end());
    }
    for(auto c : a) {
        cout << c << ' ';
    }
    cout << '\n';

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