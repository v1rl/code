#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9, M = 1e5;

/*
可以贪心地得到一个结论
如果要选择赌的话，一定只会选择一个最优的地方赌
*/

void solve() {
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    double ans = n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        double p = 1.0 * x / M;

        ans = min(ans, i + (1 / p - 1) * (i - a[i] + 1) + 1);

        /*
        t = p + (1 - p) * (t + i - a[i] + 1)
        t = 1 + (1 - p) * (i - a[i] + 1) / p;
        ans = min(ans, i + 1 + (1 - p) * (i - a[i] + 1) / p);
        */
        
    }

    printf("%.10lf\n", ans);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}