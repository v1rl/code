#include<bits/stdc++.h> 

using namespace std;
using i64 = long long;

void solve() {
	i64 n, d, l;
	cin >> n >> d >> l;
	i64 mx = (l - n - 1) * n + 1;

	i64 t = (l - n) / d;
	i64 mn = t * n;
	if(n + t * d == l) {
		mn = t * n;
	} else {
		i64 stt = (1 + t * d + d);
		if(stt >= l) {
			mn += 1;
		} else {
			mn += l - stt + 1;
		}
	}
	cout << mn << ' ' << mx << '\n';					
}

int main( ) {
	int t;
	cin >> t;
	while(t --) {
		solve();
	}
    return 0;
}