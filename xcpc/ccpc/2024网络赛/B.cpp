#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10, mod = 998244353;
int A[N];
int st[N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> dat(n);
    for(int i = 0; i < n; i ++) 
    {
        cin >> dat[i];
        st[dat[i]] ++;
    }

    A[1] = 1;
    for(int i = 2; i <= 1e6; i ++)
        A[i] = (i64)A[i - 1] * i % mod;

    sort(dat.begin(), dat.end());
    i64 ans = 0;
    for(int i = 0; i < n; i ++)
        for(int j = i + 1; j < n; j ++)
            ans += abs(dat[i] - dat[j]);

    i64 res = 1;
    int f = 0;
    for(int i = 1; i <= 1e6; i ++)
    {
        if(st[i])
        {
            f ++;
            res = res * A[st[i]] % mod;
        }
    }
    if(f > 1) res = res * 2 % mod;
    cout << ans << ' ' << res << '\n';
    return 0;
}   
