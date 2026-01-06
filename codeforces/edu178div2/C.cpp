#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// A有最大的牌且B无1或A有次大的牌
// 

void solve()
{
	int n;
	cin >> n;
	vector<int> res;
	for(int i = 1; i <= n; i ++)
	{
		char c;
		cin >> c;
		if(c == 'A') res.emplace_back(i);
	}
	if(res[0] == 1 && res.size() == n - 1 && res.back() != n)
	{
		cout << "Alice" << '\n';
	}
	else if(res.back() == n && (res[0] == 1 || res[res.size() - 2] == n - 1))
	{
		cout << "Alice" << '\n';
	}
	else cout << "Bob" << '\n';
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
    return 0;
}