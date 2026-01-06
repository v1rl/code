#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

void solve()
{
	i64 n;
	cin >> n;

	vector<i64> L(20), R(20), ans(20);
    i64 p = 1;
    int cnt = 1;
    while(p <= n)
    {
    	L[cnt] = p;
    	p *= 2;
    	ans[cnt] = p;
    	p *= 2;
    	R[cnt] = p;
    	p ++;
    	cnt ++;
    }

	int l = 1, r = cnt - 1;
	while(l < r)
	{
		int mid = l + r + 1 >> 1;
		cout << "? " << L[mid] << endl;
		int t;
		cin >> t;
		if(t == 1) r = mid - 1;
		else l = mid;
	}
	cout << "! " << (ans[l] <= n ? ans[l] : n) << endl;
}


int main()
{
    // ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;


    while(t --)
    {
        solve();
    }
    return 0;
}