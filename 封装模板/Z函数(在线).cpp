#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z(n);
    vector<int> ne(n);

    vector<vector<int>> fails(n);
    int j = 0;
    for(int i = 0; i < n; i ++) {
        if(i != 0) {
            while(j && s[i] != s[j]) {
                fails[i].emplace_back(j);
                j = ne[j - 1];
            }
            if(s[i] == s[j]) {
                for(auto x : fails[j]) {
                    fails[i].emplace_back(x);
                }
                j ++;
            } else {
                fails[i].emplace_back(0);
            }
            ne[i] = j;
        }

        for(auto x : fails[i]) {
            z[i - x] = x;
        }
    }

    while(j) {
        z[n - j] = j;
        j = ne[j - 1];
    }

    for(int i = 0; i < n; i ++) {
        cout << z[i] << ' ';
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
