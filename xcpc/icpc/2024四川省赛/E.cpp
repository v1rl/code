#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
        for(auto c : s[i]) {
            if(c == '.') {
                cnt ++;
            }
        }
    }
    if(cnt != 1 || s[0][m - 1] != '.') {
        cout << "No" << '\n';
        return;
    }

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    char ch[] = {'D', 'R', 'U', 'L'};

    int res = 0;
    for(int x = 0; x < n; x ++) {
        for(int y = 0; y < m; y ++) {
            if(s[x][y] == 'C') {
                vector<int> dir;
                for(int i = 0; i < 4; i ++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }
                    if(s[nx][ny] == ch[i]) {
                        dir.emplace_back(i);
                    }
                }
                if(dir.size() != 2 || !((dir[0] & 1) ^ (dir[1] & 1))) {
                    cout << "No" << '\n';
                    return;
                }
                res ++; 
            }
        }
    }

    if(res * 3 != n * m - 1) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
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
