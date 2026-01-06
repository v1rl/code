#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1);
    int mx = 0;
    int t = -1;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if(a[i] >= mx)
        {
            mx = a[i];
            t = i;
        }
    }

    if(t == n) cout << "No" << '\n';
    else cout << "Yes" << '\n';
}

