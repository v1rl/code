#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	/*
	int n;
	cin >> n;
 	vector<int> f(n + 1);			//恰打印i个字符的最小次数
 	iota(f.begin(), f.end(), 0);
 	int ans = 1e9;
 	for(int i = 2; i <= n; i ++)
 	{
 		for(int j = 1; ; j ++)
 		{
 			if(i * (j + 1) <= n)
 			{
 				f[i * (j + 1)] = min(f[i * (j + 1)], f[i] + 5 + j * 2);
 			}
 			else 
 			{
 				ans = min(ans, f[i] + 5 + j * 2);
 				break;
 			}
 		}
 	}
 	cout << min(ans, f[n]) << '\n';
 	*/

 	int n;
 	cin >> n;
 	int t = __lg(n) + 1;
 	t *= 7;
 	vector<int> f(t + 1);			//次数为i时最多能打印的字符数
 	f[0] = 0;
 	int ans = 0;
 	for(int i = 1; i <= t; i ++)
 	{
 		f[i] = f[i - 1] + 1;
 		for(int j = i - 7; j > 1; j -= 2)
 		{
 			f[i] = max(f[i], f[j] * ((i - j - 5) / 2 + 1));
 		}
 		if(f[i] >= n) 
 		{
 			ans = i;
 			break;
 		}
 	}
 	cout << ans << '\n';

}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}