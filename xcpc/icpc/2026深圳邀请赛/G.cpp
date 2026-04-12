#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;

const int inf = 2e9;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char p[] = {'U', 'L', 'D', 'R'};

void solve() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    vector<array<int, 2>> vec;

    if((n & 1) && (m & 1)) {
        int x, y;
        x = 1;
        for(int j = 2; j <= m; j ++) {
            vec.push_back({x, j});
        }
        y = m;
        for(int i = 2; i <= n; i ++) {
            vec.push_back({i, y});
        }

        while(y > 3) {
            y --;
            for(int i = n; i >= 2; i --) {
                vec.push_back({i, y});
            }
            y --;
            for(int i = 2; i <= n; i ++) {
                vec.push_back({i, y});
            }
        }

        x = n;

        for(int i = n; i >= 2; i --) {
            if(i & 1) {
                vec.push_back({i, 2});
                vec.push_back({i, 1});
            } else {
                vec.push_back({i, 1});
                vec.push_back({i, 2});
            }
        }

        vec.pop_back();
        int cnt = n * m - 1;
        int cx = sx, cy = sy;
        int t = vec.size();
        string ans;
        int tx, ty;
        cin >> tx >> ty;
        if(cx == 1 && cy == 1) {
            ans += 'R';
            cy = 2;
            if(cx == tx && cy == ty) {
                cout << ans << endl;
                ans.clear();
                cnt --;
                if(cnt) {
                    cin >> tx >> ty;
                }
            }
        }
        if(cx == 2 && cy == 2) {
            ans += 'U';
            cx = 1;
            if(cx == tx && cy == ty) {
                cout << ans << endl;
                ans.clear();
                cnt --;
                if(cnt) {
                    cin >> tx >> ty;
                }
            }
        }
        while(cnt) {
            for(int i = 0; i < t - 1; i ++) {
                auto [x, y] = vec[i];
                auto [nx, ny] = vec[i + 1];
                char dir;
                for(int j = 0; j < 4; j ++) {
                    if(x + dx[j] == nx && y + dy[j] == ny) {
                        dir = p[j];
                        break;
                    }
                }
                if(x == cx && y == cy) {
                    ans += dir;
                    cx = nx, cy = ny;
                }

                if(cx == tx && cy == ty) {
                    cout << ans << endl;
                    ans.clear();
                    cnt --;
                    if(cnt) {
                        cin >> tx >> ty;
                    }
                }
            }

            if(tx == 1 && ty == 1) {
                ans += 'U';
                cx = tx, cy = ty;
                if(cx == tx && cy == ty) {
                    cout << ans << endl;
                    ans.clear();
                    cnt --;
                    if(cnt) {
                        cin >> tx >> ty;
                    }
                }
                ans += 'R';
                cx = 1, cy = 2;
                if(cx == tx && cy == ty) {
                    cout << ans << endl;
                    ans.clear();
                    cnt --;
                    if(cnt) {
                        cin >> tx >> ty;
                    }
                }
            } else {
                ans += 'R';
                cx = 2, cy = 2;
                if(cx == tx && cy == ty) {
                    cout << ans << endl;
                    ans.clear();
                    cnt --;
                    if(cnt) {
                        cin >> tx >> ty;
                    }
                }
                ans += 'U';
                cx = 1, cy = 2;
                if(cx == tx && cy == ty) {
                    cout << ans << endl;
                    ans.clear();
                    cnt --;
                    if(cnt) {
                        cin >> tx >> ty;
                    }
                }
            }
        }
    } else if(n & 1) {
        int x, y;
        y = 2;
        for(int i = 1; i <= n - 1; i ++) {
            vec.push_back({i, y});
        }
        while(y != m) {
            y ++;
            for(int i = n - 1; i >= 1; i --) {
                vec.push_back({i, y});
            }
            y ++;
            for(int i = 1; i <= n - 1; i ++) {
                vec.push_back({i, y});
            }
        }
        x = n;
        for(int j = m; j >= 1; j --) {
            vec.push_back({x, j});
        }
        y = 1;
        for(int i = n - 1; i >= 1; i --) {
            vec.push_back({i, y});
        }

        int cnt = n * m - 1;
        int cx = sx, cy = sy;
        int t = vec.size();
        string ans;
        int tx, ty;
        cin >> tx >> ty;
        while(cnt) {
            for(int i = 0; i < t - 1; i ++) {
                auto [x, y] = vec[i];
                auto [nx, ny] = vec[i + 1];
                char dir;
                for(int j = 0; j < 4; j ++) {
                    if(x + dx[j] == nx && y + dy[j] == ny) {
                        dir = p[j];
                        break;
                    }
                }
                if(x == cx && y == cy) {
                    ans += dir;
                    cx = nx, cy = ny;
                }

                if(cx == tx && cy == ty) {
                    cout << ans << endl;
                    ans.clear();
                    cnt --;
                    if(cnt) {
                        cin >> tx >> ty;
                    }
                }
            }    
            ans += 'R';
            cx = 1, cy = 2;
            if(cx == tx && cy == ty) {
                cout << ans << endl;
                ans.clear();
                cnt --;
                if(cnt) {
                    cin >> tx >> ty;
                }
            }
        }
    } else {
        int x, y;
        x = 1;
        for(int j = 1; j <= m; j ++) {
            vec.push_back({x, j});
        }
        while(x != n - 1) {
            x ++;
            for(int j = m; j >= 2; j --) {
                vec.push_back({x, j});
            }
            x ++;
            for(int j = 2; j <= m; j ++) {
                vec.push_back({x, j});
            }
        }
        x = n;
        for(int j = m; j >= 1; j --) {
            vec.push_back({x, j});
        }
        y = 1;
        for(int i = n - 1; i >= 1; i --) {
            vec.push_back({i, y});
        }
        int cnt = n * m - 1;
        int cx = sx, cy = sy;
        int t = vec.size();
        string ans;
        int tx, ty;
        cin >> tx >> ty;
        while(cnt) {
            for(int i = 0; i < t - 1; i ++) {
                auto [x, y] = vec[i];
                auto [nx, ny] = vec[i + 1];
                char dir;
                for(int j = 0; j < 4; j ++) {
                    if(x + dx[j] == nx && y + dy[j] == ny) {
                        dir = p[j];
                        break;
                    }
                }
                if(x == cx && y == cy) {
                    ans += dir;
                    cx = nx, cy = ny;
                }

                if(cx == tx && cy == ty) {
                    cout << ans << endl;
                    ans.clear();
                    cnt --;
                    if(cnt) {
                        cin >> tx >> ty;
                    }
                }
            }    
            ans += 'R';
            cx = 1, cy = 2;
            if(cx == tx && cy == ty) {
                cout << ans << endl;
                ans.clear();
                cnt --;
                if(cnt) {
                    cin >> tx >> ty;
                }
            }
        }
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
