#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://www.acwing.com/problem/content/description/221/

/*
博弈论SG函数经典应用题
但本题不能直接套用SG函数，因为题目规则不是无法操作的人判负，而是第一个达成某状态（达到1*1）的人判胜
所以我们需要手动模拟小状态，并以特判后的小状态为SG函数的边界
*/

const int N = 200;

void solve() {
	vector f(N + 1, vector(N + 1, -1));
	int n, m;
	while(cin >> n >> m, n || m) {
		f[2][2] = f[2][3] = f[3][2] = 0;
		auto sg = [&](auto &&self, int x, int y) -> int {
			if(x > y) {
				swap(x, y);
			}
			if(f[x][y] != -1) {
				return f[x][y];
			}  

			unordered_set<int> S;
			for(int i = 2; i <= x / 2; i ++) {
				S.insert(self(self, i, y) ^ self(self, x - i, y));
			}
			for(int i = 2; i <= y / 2; i ++) {
				S.insert(self(self, x, i) ^ self(self, x, y - i));
			}

			int res = 0;
			while(S.count(res)) {
				res ++;
			}
			return f[x][y] = f[y][x] = res;
		};

		cout << (sg(sg, n, m) ? "WIN" : "LOSE") << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
    	solve();
    }
}