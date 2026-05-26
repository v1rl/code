#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> cnt(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        cnt[a[i]] ++;
    }

    for(int i = 1; i <= n; i ++) {
        if(cnt[i] > 2) {
            cout << -1 << '\n';
            return;
        }
    }

    vector vis(2, vector(n + 1, 0));
    vector ans(2, vector(n + 1, 0));
    for(int i = 1; i <= n; i ++) {
        if(cnt[a[i]] == 1) {
            ans[0][i] = a[i];
            ans[1][i] = a[i];
            vis[0][a[i]] = true;
            vis[1][a[i]] = true;
        } else if(cnt[a[i]] == 2) {
            ans[0][i] = a[i];
            vis[0][a[i]] = true;
            cnt[a[i]] = 3;
        } else {
            ans[1][i] = a[i];
            vis[1][a[i]] = true;
        }
    }

    for(int i = 0; i < 2; i ++) {
        int cnt = 1;
        for(int j = 1; j <= n; j ++) {
            if(!ans[i][j]) {
                while(vis[i][cnt]) {
                    cnt ++;
                }
                ans[i][j] = cnt;
                vis[i][cnt] = true;
            }
        }
    }

    for(int i = 0; i < 2; i ++) {
        for(int j = 1; j <= n; j ++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}