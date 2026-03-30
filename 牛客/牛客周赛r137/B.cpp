#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int op = 1;
    deque<char> q;
    for(auto c : s) {
        if(c == '!') {
            op ^= 1;
        } else if(c == '-') {
            if(q.empty()) {
                continue;
            }
            if(op) {
                q.pop_back();
            } else {
                q.pop_front();
            }
        } else {
            if(op) {
                q.push_back(c);
            } else {
                q.push_front(c);
            }
        }
    }

    if(q.empty()) {
        cout << "Empty" << '\n';
    } else {        
        while(q.size()) {
            cout << q.front();
            q.pop_front();
        }
        cout << '\n';
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
