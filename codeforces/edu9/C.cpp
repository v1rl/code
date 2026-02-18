#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
考虑到c、cb这种情况
我们排序时不能单单只比较字符串本身的大小
注意到：排序比大小时，使用 x+y<y+x 的规则排序，局部符合条件，整体排序后全局也符合条件
*/

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        a[i] = s;
    }

    sort(a.begin(), a.end(), 
        [&](string x, string y) {
            return x + y < y + x;
        });

    for(auto x : a) {
        cout << x;
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
