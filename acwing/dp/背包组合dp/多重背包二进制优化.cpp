#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 3e4;
int v[N], w[N], cnt = 0;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        int cv, cw, s;
        cin >> cv >> cw >> s;
        int k = 1;
        while(s >= k)
        {
            cnt ++;
            v[cnt] = cv * k;
            w[cnt] = cw * k;
            s -= k;
            k *= 2;
        }
        if(s) cnt ++, v[cnt] = cv * s, w[cnt] = cw * s;
    }

    vector<int> f(m + 1);
    for(int i = 1; i <= cnt; i ++)
    {
        for(int j = m; j >= v[i]; j --)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << '\n';
}