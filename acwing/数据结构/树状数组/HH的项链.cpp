#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10;

template<typename T>
struct Fenwick
{
    int n;
    vector<T> a;

    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, const T &v)
    {
        for(int i = x; i <= n; i += i & -i)
            a[i] += v;
    }

    T sum(int x)
    {
        T res{};
        for(int i = x; i; i -= i & -i)
            res += a[i];
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    Fenwick<int> tr(n);
 	vector<int> lst(N);
 	vector<int> a(n + 1);
 	for(int i = 1; i <= n; i ++)
 	{
 		int x;
 		cin >> x;
 		a[i] = lst[x];
 		lst[x] = i;
 	}

 	int m;
 	cin >> m;
 	vector<array<int, 2>> query;
 	query.reserve(m * 2);
 	vector<int> ql(m + 1);
 	for(int i = 1; i <= m; i ++)
 	{
 		int l, r;
 		cin >> l >> r;
 		query.push_back({l, i});
 		query.push_back({r, i});
 		ql[i] = l;
 	}

 	sort(query.begin(), query.end());
 	vector<int> ans(m + 1, -1);
 	int k = 0;
 	for(int i = 1; i <= n; i ++)
 	{
 		tr.add(a[i] + 1, 1);
 		while(k < 2 * m && query[k][0] == i)
 		{
 			auto [pos, id] = query[k];
 			if(ans[id] == -1)
 			{
 				ans[id] = tr.sum(pos);
 				if(a[i] <= pos) ans[id] --;
 			}
 			else
 			{
 				ans[id] = tr.sum(ql[id]) - ans[id];
 			}
 			k ++;
 		}
 	}
 	for(int i = 1; i <= m; i ++)
 		cout << ans[i] << '\n';
}