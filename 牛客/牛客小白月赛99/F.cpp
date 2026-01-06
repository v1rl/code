#include<bits/stdc++.h>
using namespace std;
using i64 = long long;      //WA
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int state[N], cnt;

int check(int mid)
{
    vector<int> f(mid + 1);
    f[0] = 1;
    for(int i = 1; i <= cnt; i ++)
        for(int j = state[i]; j <= mid; j ++)
            f[j] += f[j - state[i]];

    for(int i = mid; i >= 0 ; i --) if(f[i]) return i;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n, m, t;
        cin >> n >> m >> t;
        vector<int> dat(m);
        for(int i = 0; i < m; i ++) cin >> dat[i];
        sort(dat.begin(), dat.end());
        cnt = 0;
        vector<bool> st(2e5 + 10);
        for(int i = 0; i < m - 1; i ++)
        {
            int t = dat[i + 1] - dat[i];
            if(!st[t]) state[++ cnt] = t;
        }
        if(t < n) cout << 0 << '\n';
        else
        {
            int r = (t - n) / 2;
            int ans = check(r);
            cout << n + ans * 2 << '\n';
        }
    }
    return 0;
}   