#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int P = 131;
const int N = 1e5 + 10;
u64 h[N], p[N];

u64 get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = '#' + s;
    p[0] = 1;
    for(int i = 1; i <= n; i ++)
    {
        h[i] = h[i - 1] * P + s[i];
        p[i] = p[i - 1] * P;
    }

    while(q --)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        u64 w1 = get(l1, r1), w2 = get(l2, r2);
        if(w1 == w2) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}