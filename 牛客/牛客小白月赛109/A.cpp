#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int n;
    int t = 19260817 + 114514;

    cin >> n;
    cout << min(n, t + 1) << '\n';
}