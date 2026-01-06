#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
找到所有可交换的位置
若最终可以交换到这个位置，一定有该位置下标(1-index) >= 交换次数
显然具有单调性，二分答案找到这个位置输出即可
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> p;
    for(int i = 0; i < n; i ++) {
        if(a[i] > m) {
            p.emplace_back(i);
        }
    }
    // 需要注意，最后一个位置也要统计到可交换位置中
    p.emplace_back(n);

    int l = 0, r = p.size() - 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(p[mid] + 1 >= p.size() - 1 - mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << p[l] + 1 << '\n';
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
