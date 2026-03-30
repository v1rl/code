#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;
const i64 inf = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<i64> a(n);
	for(i64 i = 0; i < n; i ++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	i64 l = a[0];
	set<array<i64, 2>> S;
	for(i64 i = 1; i < n; i ++) {
		if(a[i] != a[i - 1] + 1) {
			S.insert({l, a[i - 1] + 1});
			l = a[i];
		}
	}
	S.insert({l, a[n - 1] + 1});


	while(m --) {
		i64 op, x, L;
		cin >> op >> x >> L;

		if(op == 1) {
			i64 edd = x + L;
            i64 add = 0;
            
            auto it = S.upper_bound({x, inf});
            if (it != S.begin()) {
                auto prev = std::prev(it);
                if ((*prev)[1] > x) it = prev;
            }
            
            while (it != S.end()) {
                auto [l, r] = *it;
                // 判断是否被推土机扫到 或 撞上雪球
                if (l <= edd + add) {
                    if (l < x) {
                        // 左边有一截没被扫到，断开
                        add += r - x;
                        it = S.erase(it);
                        S.insert({l, x});
                    } else {
                        // 整个区间被吸收
                        add += r - l;
                        it = S.erase(it);
                    }
                } else {
                    break; // 连锁反应停止
                }
            }
            
            if (add > 0) {
                S.insert({edd, edd + add});
            }
		} else {
			i64 edd = x - L; // 左推雪球的右边界(不包含)
            i64 add = 0;
            
            // 找到第一个左端点 >= x 的区间，它的前一个就是我们要看的
            auto it = S.lower_bound({x, -inf});
            if (it != S.begin()) {
                it --;
                while (true) {
                    auto [l, r] = *it;
                    bool has_prev = (it != S.begin());
                    auto prv = it;
                    if (has_prev) prv--;
                    
                    // 判断是否被推土机扫到 或 被左滚的雪球撞上
                    if (r >= edd - add) {
                        if (r > x) {
                            // 右边有一截在 x 或更右边，没被扫到，断开
                            add += x - l;
                            S.erase(it);
                            S.insert({x, r});
                        } else {
                            // 整个区间被吸收
                            add += r - l;
                            S.erase(it);
                        }
                        
                        if (has_prev) it = prv; // 继续往左找
                        else break;
                    } else {
                        break;
                    }
                }
            }
            
            if (add > 0) {
                // 左堆积的区间为 [edd - add, edd)
                S.insert({edd - add, edd});
            }
		}
	}


	for(auto [l, r] : S) {
		for(i64 i = l; i < r; i ++) {
			cout << i << ' ';
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	i64 t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}