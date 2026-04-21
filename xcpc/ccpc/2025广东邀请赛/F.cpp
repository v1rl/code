#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int m;
    cin >> m;
    vector<int> time(n, -1);
    vector<int> add(n);
    vector<int> vis(n);
    vector<int> ano;
    for(int i = 0; i < m; i ++) {
        int t;
        char c;
        string st;
        cin >> t >> c >> st;
        int ch = c - 'A';
        if(st == "rj" && time[ch] == -1) {
            add[ch] += 20;
        }
        if(st == "ac" && time[ch] == -1) {
            time[ch] = t;
        }
        if(st == "pd" && time[ch] == -1) {
            time[ch] = t;
            vis[ch] = true;
            ano.emplace_back(t + add[ch]);
        }
    }

    int sum = 0;
    int num = 0;
    for(int i = 0; i < n; i ++) {
        if(!vis[i] && time[i] != -1) {
            sum += add[i] + time[i];
            num ++;
        }
    }

    sort(ano.begin(), ano.end());
    int ans = 0;
    int i = 0;
    while(i < ano.size() && (ans + num < a || (ans + num == a && sum >= b))) {
        ans ++;
        sum += ano[i];
        i ++;
    }

    if(ans + num > a || (ans + num == a && sum < b)) {
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
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
