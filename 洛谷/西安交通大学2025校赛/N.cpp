#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

template<class Info>
struct Segmentree {
	int n;
	vector<Info> info;

	Segmentree(int n_) : n(n_), info(4 * n + 1) {};
	Segmentree(vector<int> a) : Segmentree(a.size()) {
		function<void(int, int, int)> build = [&](int p, int l, int r) {
			if(l == r) {
				info[p] = {a[l]};
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

	void modify(int p, int l, int r, int pos, int x) {
		if(l == r) {
			info[p] = {x};
			return;
		}
		int mid = l + r >> 1;
		if(pos <= mid) modify(p << 1, l, mid, pos, x);
		else modify(p << 1 | 1, mid + 1, r, pos, x);
		pushup(p);
	}

	void modify(int pos, int x) {
		modify(1, 1, n, pos, x);
	}

	Info query(int p, int l, int r, int x, int y) {
		if(r < x || l > y) return Info{};
		if(l >= x && r <= y) return info[p];
		int mid = l + r >> 1;
		return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y);
	}

	Info query(int x, int y) {
		if(x > y) return Info{};
		return query(1, 1, n, x, y);
	}
};

struct Info {
	int mn = inf;
};

Info operator+(Info a, Info b) {
	Info c;
	c.mn = min(a.mn, b.mn);
	return c;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> pos(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	Segmentree<Info> tr(a);
	int m;
	cin >> m;
	while(m --) {
		int l, r;
		cin >> l >> r;
		int mn = min(tr.query(1, l - 1).mn, tr.query(r + 1, n).mn);
		if(mn >= n) {
			cout << "peace" << '\n';
			continue;
		}
		int x = pos[mn], y = pos[mn + 1];
		tr.modify(x, mn + 1), tr.modify(y, mn);
		swap(pos[mn], pos[mn + 1]);
		cout << mn << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}