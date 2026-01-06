#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> PII;
typedef long long LL;
PII dat[N];
LL lsum[N], rsum[N];
int n;

void solve()
{
	int x;
	cin >> x;
	int l = 1, r = n;
	while(l < r)
	{
		int mid = (l + r + 1) >> 1;
		if(x >= dat[mid].first) l = mid;
		else r = mid - 1;
	}
	LL ans = 0;
	if(dat[l].first <= x) ans = lsum[l] + rsum[l + 1] * x;
	else ans = rsum[l] * x;
	cout << ans << "\n";
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> dat[i].second;
	for(int i = 1; i <= n; i ++) cin >> dat[i].first;

	sort(dat + 1, dat + n + 1);

	for(int i = 1; i <= n; i ++) lsum[i] = lsum[i - 1] + dat[i].first * dat[i].second;
	for(int i = n; i; i --) rsum[i] = rsum[i + 1] + dat[i].second;

	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	return 0;
}