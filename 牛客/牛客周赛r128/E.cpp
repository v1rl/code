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

    if(pos.size()) {
        int kep;
        if(pos.size() % 2 == 0) {
            kep = -1;
        } else {
            kep = pos[pos.size() / 2];
            for(auto c : pos) {
                if(c + 1 < n && s[c + 1] == '2') {
                    kep = min(kep, c);
                    break;
                }
            }
        }

        for(int l = 0, r = pos.size() - 1; l < r; l ++, r --) {
            if(pos[l] == kep) {
                l ++;
            } else if(pos[r] == kep) {
                r --;
            }
            s[pos[l]] = '#';
            s[pos[r]] = '2';
        }
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