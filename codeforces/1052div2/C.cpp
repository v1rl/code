#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
每个1所在位置都是它本身
每个1所在位置要满足左边所有数比它小，右边所有数比它大
每个0所在位置不能是它本身
*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '0') {
            if((i == 0 || s[i - 1] == '1') && (i == n - 1 || s[i + 1] == '1')) {
                cout << "NO" << '\n';
                return;
            }
        } else {
            pos.emplace_back(i + 1);
        }
    }
    cout << "YES" << '\n';

    int lst = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') {
            lst = i + 1;
            cout << i + 1 << ' ';
        } else {
            if(i == n - 1) {
                cout << lst + 1 << ' ';
            } else {
                if(s[i + 1] == '0') {
                    cout << i + 2 << ' ';
                } else {
                    cout << lst + 1 << ' ';
                }
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
    while(t --) {
        solve();
    }
    return 0;
}