#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
const int N = 2e5 + 10, M = 1010;
int v[M], w[M], f[N];
int lst[N];
int n;

int a[N];

void solve() {
    int k;
    cin >> k;
    while(k != 0) {
        int t = lst[k];
        for(int i = 0; i < t; i ++) {
            cout << 1;
        }
        k -= v[t];
        if(k != 0) cout << 0;
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    for(int i = 1; i; i ++) {
        v[i] = 1ll * i * (i + 1) / 2;
        w[i] = i + 1;
        if(v[i] >= N) {
            n = i - 1;
            break;
        }
    }

    for(int i = 1; i < N; i ++) {
        f[i] = inf;
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = v[i]; j < N; j ++) {
            int cur = f[j - v[i]] + w[i];
            if(cur < f[j]) {
                lst[j] = i;
                f[j] = cur;
            }
        }
    }


    while(t --)
    {
        solve();
    }
}