#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 4e5 + 5;

// 123 124
// 213 214

// 112234 		-2

// 12343 12344

// 1122333444 	-24

// 9129 9130
// 01123999		-1

void solve()
{
	int n = 100;
	for(int i = 1; i <= n; i ++)
	{
		string t = to_string(i) + to_string(i + 1);
		sort(t.begin(), t.end());
		cout << t << '\n';
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