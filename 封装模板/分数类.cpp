#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
const int inf = 1e9 + 7;

struct frac
{
	i64 x, y;
	frac(i64 x_ = 0) : x(x_), y(1) {};

	frac(i64 a, i64 b)
	{
		if(!b) assert(0);
		if(!a) x = 0, y = 1;
		else
		{
			bool neg = 0;
			if((a < 0) != (b < 0)) neg = 1;
			if(a < 0) a = -a;
			if(b < 0) b = -b;
			i64 g = __gcd(a, b);
			x = a / g;
			y = b / g;
			if(neg) x = -x;
		}
	}

	friend frac operator+(const frac &a, const frac &b)
	{
		return frac(a.x * b.y + b.x * a.y, a.y * b.y);
	}
	friend frac operator-(const frac &a, const frac &b)
	{
		return frac(a.x * b.y - b.x * a.y, a.y * b.y);
	}
	friend frac operator*(const frac &a, const frac &b)
	{
		return frac(a.x * b.x, a.y * b.y);
	}
	friend frac operator/(const frac &a, const frac &b)
	{
		return frac(a.x * b.y, b.x * a.y);
	}
	friend bool operator<(const frac &a, const frac &b)
	{
		return (i128)a.x * b.y < (i128)b.x * a.y;
	}
	friend bool operator>(const frac &a, const frac &b)
	{
		return (i128)b.x * a.y > (i128)b.x * a.y;
	}
};

void solve()
{
	// (x - 1) / 2 + n / x
	int n;
	cin >> n;
	int x1 = sqrt(2 * n);
	int x2 = ceil(sqrt(2 * n));

	frac ans1 = frac{x1, 2} + frac{n, x1} - frac{1, 2};
	frac ans2 = frac{x2, 2} + frac{n, x2} - frac{1, 2};
	if(ans1 < ans2) cout << ans1.x << ' ' << ans1.y << '\n';
	else cout << ans2.x << ' ' << ans2.y << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}