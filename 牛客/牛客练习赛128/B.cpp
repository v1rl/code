#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 510;
int f[N * N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int , 2>> dat(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int a, b;
        cin >> a >> b;
        dat[i] = {b, a};
    }


    int ans = 0;
    sort(dat.begin() + 1, dat.begin() + 1 + n);

    int sum = 0;
    int val = 0;
    int id = 0;
    for(int i = 1; i <= n; i ++)
    {
    	if(dat[i][0] <= m) 
    	{
    		sum += m - dat[i][0];
    		val += dat[i][1];
    	}
    	else
    	{
    		id = i;
    		break;
    	}
    }
    // memset(f, -0x3f, sizeof f);
    // f[sum] = val;
    // for(int i = id; i <= n; i ++)
    // {
    //     int d = m - dat[i][0];
    //     for(int j = 0; j <= sum; j ++)
    //     {
    //         if(j + d >= 0)
    //         {
    //             f[j + d] = max(f[j + d], f[j] + dat[i][1]);
    //             ans = max(ans, f[j + d]);
    //         }   
    //     }
    // }

    for(int i = id; i <= n; i ++)
    {
        int v = dat[i][0] - m;
        for(int j = sum; j >= v; j --)
            f[j] = max(f[j], f[j - v] + dat[i][1]);
    }

    cout << f[sum] + val << '\n'; 
}