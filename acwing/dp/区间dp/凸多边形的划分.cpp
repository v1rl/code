#include<bits/stdc++.h>
using namespace std;
const int N = 210, M = 110;
int a[N];

struct hh
{
    int a[M], sz;
    void clear()
    {
        memset(a, 0, sizeof a), sz = 0;
    }
    void jw()
    {
        for(int i = 1; i <= sz; i ++) a[i + 1] += a[i] / 10, a[i] %= 10;
        if(a[sz + 1]) sz ++;
    }
    hh operator +(hh x)
    {
        hh s; s.clear(), s.sz = max(sz, x.sz);
        for(int i = 1; i <= s.sz; i ++) s.a[i] = a[i] + x.a[i];
        s.jw();
        return s;
    }
    hh operator *(hh x)
    {
        hh s; s.clear(), s.sz = sz + x.sz - 1;
        for(int i = 1; i <= sz; i ++)
            for(int j = 1; j <= x.sz; j ++)
                s.a[i + j - 1] += a[i] * x.a[j];
        s.jw();
        return s;
    }
    hh operator -(hh x)
    {
        hh s; s.clear(), s.sz = sz;
        for(int i = 1; i <= s.sz; i ++) s.a[i] = a[i] - x.a[i];
        for(int i = 1; i <= s.sz; i ++) if(s.a[i] < 0) s.a[i] += 10, s.a[i + 1] --;
        while(s.sz > 1 && s.a[s.sz] == 0) s.sz --;
        return s; 
    }
    hh operator /(int x)
    {
        hh s; s.clear(), s.sz = 0;
        for(int i = sz, t = 0; i; i --)
        {
            t = t * 10 + a[i];
            s.a[i] = t / x;
            t %= x;
            if(s.a[i]) s.sz = max(s.sz, i);
        }
        return s;
    }
    bool operator <(hh x) const
    {
        if(sz != x.sz) return sz < x.sz;
        for(int i = sz; i; i --)
            if(a[i] != x.a[i]) return a[i] < x.a[i];
        return 0;
    }
    void print()
    {
        for(int i = sz; i; i --) cout << a[i];
        cout << '\n';
    }
}w[N], f[N][N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) 
	{
		int x;
		cin >> x;
		int cnt = 0;
		while(x)
		{
			w[i].a[++ cnt] = x % 10;
			x /= 10;
		}
		w[i].sz = cnt;
	}

	for(int len = 3; len <= n; len ++)
		for(int l = 1; l + len - 1 <= n; l ++)
		{
			int r = l + len - 1;
			for(int k = l + 1; k < r; k ++)
			{
				hh res = f[l][k] + f[k][r] + w[l] * w[k] * w[r];
				if(f[l][r].sz == 0 || res < f[l][r]) f[l][r] = res;
			}
		}

	f[1][n].print();
}
