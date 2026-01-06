#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;
#define int long long

template<class Info, class Tag>
struct LazySegmenTree {
	int n;
	vector<Info> info;
	vector<Tag> tag;

	LazySegmenTree(int n_) : n(n_), info(4 * n + 1), tag(4 * n + 1) {};
	LazySegmenTree(vector<Info> a) : LazySegmenTree(a.size() - 1) {
		function<void(int, int, int)> build = [&](int p, int l, int r) {
			// cerr << 'h';
			if(l == r) {
				info[p] = a[l];
				return;
			}
			int mid = l + r >> 1;
			build(p << 1, l, mid);
			build(p << 1 | 1, mid + 1, r);
			pushup(p);
		};
		build(1, 1, n);
	}

	void pushup(int p) {
		info[p] = info[p << 1] + info[p << 1 | 1];
	}

	void apply(int p, const Tag &t) {
		info[p].apply(t);
		tag[p].apply(t);
	}

	void pushdown(int p) {
		apply(p << 1, tag[p]);
		apply(p << 1 | 1, tag[p]);
		tag[p] = Tag();
	}

	void rangeApply(int p, int l, int r, int x, int y, const Tag &t) {
		if(r < x || l > y) {
			return;
		}
		if(x <= l && r <= y) {
			apply(p, t);
			return;
		}
		pushdown(p);
		int mid = l + r >> 1;
		rangeApply(p << 1, l, mid, x, y, t);
		rangeApply(p << 1 | 1, mid + 1, r, x, y, t);
		pushup(p);
	}

	void rangeApply(int x, int y, const Tag &t) {
		rangeApply(1, 1, n, x, y, t);
	}

	void modify(int p, int l, int r, int pos, int t) {
		if(l == r) {
			info[p].sum = t;
			return;
		}
		int mid = l + r >> 1;
		pushdown(p);
		if(pos <= mid) {
			modify(p << 1, l, mid, pos, t);
		} else {
			modify(p << 1 | 1, mid + 1, r, pos, t);
		}
		pushup(p);
	}

	void modify(int pos, int t) {
		modify(1, 1, n, pos, t);
	}

	Info query(int p, int l, int r, int x, int y) {
		if(r < x || l > y) {
			return Info();
		}
		if(x <= l && r <= y) {
			return info[p];
		}
		pushdown(p);
		int mid = l + r >> 1;
		return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x ,y);
	}

	Info query(int x, int y) {
		return query(1, 1, n, x, y);
	}
};

struct Tag {
	i64 mul = 1;
	void apply(const Tag &t) {
		mul *= t.mul;
		mul %= mod;
	}
};

struct Info {
	i64 sum = 0;
	void apply(const Tag &t) {
		sum *= t.mul;
		sum %= mod;
	}
};

Info operator+ (Info a, Info b) {
	Info c;
	c.sum = (a.sum + b.sum) % mod;
	return c;
}

template<class T>
struct Fenwick {
	int n;
	vector<T> a;

	Fenwick(int n_) : n(n_), a(n + 1) {};

	void add(int x, const T &v) {
		for(int i = x; i <= n; i += i & -i) {
			a[i] += v;
		}
	}

	T sum(int x) {
		T res{};
		for(int i = x; i; i -= i & -i) {
			res += a[i];
		}
		return res;
	}

	T rangeSum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

i64 qmi(i64 a, i64 b) {
	i64 res = 1;
	while(b) {
		if(b & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	vector<int> kth;
	kth.reserve(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		kth.emplace_back(a[i]);
	}

	sort(kth.begin(), kth.end());
	kth.erase(unique(kth.begin(), kth.end()), kth.end());
	int m = kth.size();

	auto rk = [&](int x) -> int {
		return lower_bound(kth.begin(), kth.end(), x) - kth.begin() + 1;
	};
	vector<int> ls(n + 1, -1);
	vector<int> es(m + 1, -1);
	for(int i = 0; i < n; i ++) {
		int pos = rk(a[i]);
		if(es[pos] != -1) {
			ls[i] = es[pos];
		}
		es[pos] = i;
	}

	// cout << ls[2] << '\n';

	LazySegmenTree<Info, Tag> tr(m + 1);

	vector<int> f(n);
	f[0] = 100;
	tr.modify(rk(a[0]), 100);

	for(int i = 1; i < n; i ++) {
		int pos = rk(a[i]);
		i64 res = 0;
		res += 1ll * tr.query(1, pos - 1).sum * (100 - x) % mod;
		res %= mod;
		res += 1ll * tr.query(pos + 1, m).sum * x % mod;
		res %= mod;

		res += 1ll * tr.query(pos, pos).sum * 100 % mod;
		res %= mod;

		f[i] = res;
		if(ls[i] != -1) {
			cout << ls[i] << '\n';
			f[ls[i]] = 0;
		}
		tr.modify(pos, res);
		tr.rangeApply(1, pos - 1, {x});
		tr.rangeApply(pos + 1, m, {100 - x});
	}

	// for(int i = 0; i < n; i ++) {
	// 	cout << f[i] << '\n';
	// }

	vector<int> qs1(200001), qs2(200001), qs3(200001);
	qs1[0] = qs2[0] = qs3[0] = 1;
	for(int i = 1; i <= 200000; i ++) {
		qs1[i] = 1ll * qs1[i - 1] * (100 - x) % mod;
		qs2[i] = 1ll * qs2[i - 1] * x % mod;
		qs3[i] = 1ll * qs3[i - 1] * 100 % mod;
	}


	i64 ans = 0;
	Fenwick<int> Ftr(m + 1);

	int bs = qmi(qmi(100, mod - 2), n);

	for(int i = n - 1; i >= 0; i --) {
		int pos = rk(a[i]);
		i64 res = 1;
		res *= qs1[Ftr.rangeSum(1, pos - 1)];
		res %= mod;
		res *= qs2[Ftr.rangeSum(pos + 1, m)];
		res %= mod;
		res *= qs3[Ftr.rangeSum(pos, pos)];
		res %= mod;

		res *= bs;
		res %= mod;

		res *= f[i];
		res %= mod;
		cout << res << '\n';

		// cout << pos << '\n';
		ans += 1ll * res * a[pos - 1] % mod;
		ans %= mod;

		Ftr.add(pos, 1);
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
    return 0;
}