#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    int pos[3];
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        char c;
        cin >> c;
        if(c == '1') {
            pos[cnt] = i;
            cnt ++;
        }
    }

    if(pos[1] - pos[0] == pos[2] - pos[1]) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}