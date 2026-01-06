#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 4e5 + 5;

// 在26情况下，想要添加2个都不够，后面就必须有完整的两段a~z，顺序不限
// 取后续出现循环对的次数，然后 +1

// 怎么找到当前字段最右侧对应的位置？
// 二分答案(X)
// 预处理当前位置下一个字母的位置(自动机？)

void solve()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = '#' + s;

	int sum = 0;
	int level = 0;
	vector<int> suf(n + 2);
	vector<int> vis(k);
	for(int i = n; i >= 1; i --)
	{
		int ch = s[i] - 'a';
		if(!vis[ch])
		{
			vis[ch] = true;
			sum ++;
		}
		if(sum == k)
		{
			sum = 0;
			level ++;
			vis.assign(k, false);
		}
		suf[i] = level;
	}

	vector f(n + 1, vector(26, 0));
	vector<int> net(26);
	for(int i = n; i >= 0; i --)
	{
		int ch = s[i] - 'a';
		for(int j = 0; j < 26; j ++)
		{
			f[i][j] = net[j];
		}
		if(i != 0) net[ch] = i;
	}

	int q;
	cin >> q;
	while(q --)
	{
		string t;
		cin >> t;

		int k = 0;
		for(int i = 0; i < t.size(); i ++)
		{
			int ch = t[i] - 'a';
			if(f[k][ch]) k = f[k][ch];
			else
			{
				k = -1;
				break;
			}
		}

		if(k == -1) cout << 0 << '\n';
		else cout << suf[k + 1] + 1 << '\n';
	}
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --)
    {
        solve();
    }
    return 0;
}