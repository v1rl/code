#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
有两个不存在的数 --这两个数和第三和数循环放 X

有一个不存在的数 --不存在的数和其他数循环放，首位避开最后一个数

全部存在 --照着顺序输出
*/


void solve() {
    int n, k;
    cin >> n >> k;
    unordered_set<int> S;
    vector<int> a(n);
    vector<int> st(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        S.insert(a[i]);
        st[a[i]] = true;
    }
    if(S.size() == n) {
        for(int i = 0; i < k; i ++) {
            cout << a[i] << ' ';
        }
    } else {
        for(int i = 1; i <= n; i ++) {
            if(!st[i]) {
                if(n == 2) {
                    for(int j = 0; j < k; j ++) {
                        if(j & 1) {
                            cout << i << ' ';
                        } else {
                            cout << 3 - i << ' ';
                        }
                    }
                } else {
                    int x = i, y = 1;
                    if(y == x) y ++;
                    if(y == a[n - 1]) y ++;
                    if(y == x) y ++;
                    int stt = y;
                    for(int j = 0; j < k; j ++){ 
                        if(j % n == 0) {
                            cout << i << ' ';
                        } else {
                            if(y == n + 1) {
                                y -= n;
                            }
                            cout << y << ' ';
                            y ++;
                            if(y == n + 1) {
                                y -= n;
                            }
                            if(y == x) y ++;
                        }
                    }
                }
                break;
            }
        }
    }
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    // cout << (1 << 13) << '\n';
    while(t --) {
        solve();
    }
    return 0;
}