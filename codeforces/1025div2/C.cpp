#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

// 2 -> digit 让数小于 17
// 4 -> 确认为1
// 1 -> 变化为目标值

// 81 -> 79 -> 16
// 8 4 2 1 -> 16

void solve()
{
	int n;
	cin >> n;
	int t;
	cout << "digit" << endl;
	cin >> t;
	cout << "digit" << endl;
	cin >> t;

	int p = 8;
	while(p)
	{
		cout << "add " << -p << endl;
		cin >> t;
		p /= 2;
	}

	cout << "mul " << n << endl;
	cin >> t;
	cout << "!" << endl;
	cin >> t;
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