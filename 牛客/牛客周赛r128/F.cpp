#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 2e9;

/*
*/

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> pos;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') {
            pos.emplace_back(i);
        }
    }

    for(int i = 0; i < n; i ++) {
        if(s[i] != '1') {
            continue;
        }
        int l = i, r = i;
        while(r + 1 < n && s[r + 1] == '1') {
            r ++;
        }
        if(r + 1 < n && s[r + 1] == '0') {
            int cur = r;
            while(cur >= l && pos.back() > r) {
                s[pos.back()] = '2';
                pos.pop_back();
                s[cur] = '#';
                cur --;
            }
            if(pos.back() <= r) {
                break;
            }
        }
        i = r;
    }

    for(int i = 0; i < n; i ++) {
        if(s[i] == '#') {
            continue;
        }
        cout << s[i];
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