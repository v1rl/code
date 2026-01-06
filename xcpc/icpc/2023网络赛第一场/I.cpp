#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*
注意：
本题的空间和时间都比较极限，且多数时间都花在运算上，此时最好不要用#define int long long

求可能性个数
题目中给定了个数约束，相邻不相等约束
注意到：我们可以以末位及其字母为基本维度，用dp控制转移数组处理特定约束下的情况数
常规的 f[i][j][0/1][0/1][0/1];
每次转移都要嵌套枚举当前字母、上一维状态(建议状压)以及上一维字母实现转移，复杂度来到了n*62^2*8，显然不可接受
考虑到我们只使用上一维数据，且因为需要同时用到当前维度和上一维度，我们选择滚动数组而非降维
考虑到每次利用上一维字母转移时都几乎使用了全体(一般为全体-1)，我们可以预处理出总和，省去对上一维字母的枚举

trick：状压后通过 “旧状态 | 当前字母带来的状态 得到 新状态” 的方式维护状态转移

dp单独预处理i == 1的情况——分类讨论的滚动遍历转移——求和
*/

int f[2][62][8];
int base[3] = {0, 26, 52};
int op[3] = {1, 2, 4};

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = '#' + s;

	if(s[1] >= 'A' && s[1] <= 'Z') {
		int c = base[1] + s[1] - 'A';
		f[1][c][op[1]] = 1;
	} else if(s[1] >= '0' && s[1] <= '9') {
		int c = base[2] + s[1] - '0';
		f[1][c][op[2]] = 1;
	} else if(s[1] >= 'a' && s[1] <= 'z') {
		int c = base[0] + s[1] - 'a';
		f[1][c][op[0]] = 1;
		// 需要注意，这里是将s[i]视作大写，但s[i]并非真正的大写，应该-'a'，而非-'A'
		c = base[1] + s[1] - 'a';
		f[1][c][op[1]] = 1;
	} else {
		for(int c = 0; c < 62; c ++) {
			if(c >= 0 && c < 26) {
				f[1][c][op[0]] = 1;
			} else if(c >= 26 && c < 52) {
				f[1][c][op[1]] = 1;
			} else if(c >= 52 && c < 62) {
				f[1][c][op[2]] = 1;
			}
		}
	}

	for(int i = 2; i <= n; i ++) {
		int cur = i & 1;

		// 需要注意，滚动数组使用时需要预先清空(或预处理)
		for(int c = 0; c < 62; c ++) {
			for(int k = 0; k < 8; k ++) {
				f[cur][c][k] = 0;
			}
		}

		vector<int> sum(8);
		for(int j = 0; j < 8; j ++) {
			for(int c = 0; c < 62; c ++) {
				sum[j] += f[cur ^ 1][c][j];
				// 需要注意，因为f在执行过程中可能为负数，若通过减法达成取模目的，我们不能只判正越界情况
				// 因为全判正负又很麻烦，我们先尝试直接取模，事实上，这并不会超时
				sum[j] %= mod;
			}
		}
		if(s[i] >= 'a' && s[i] <= 'z') {
			for(int k = 0; k < 8; k ++) {
				int c = base[0] + s[i] - 'a';
				// 需要注意，三个数相加/相减显然会爆int，所以我们需要对右侧两个数的运算也取模一次
				f[cur][c][k | op[0]] += (sum[k] - f[cur ^ 1][c][k]) % mod;
				f[cur][c][k | op[0]] %= mod;
				c = base[1] + s[i] - 'a';
				f[cur][c][k | op[1]] += (sum[k] - f[cur ^ 1][c][k]) % mod;	
				f[cur][c][k | op[1]] %= mod;
			}
		} else if(s[i] >= 'A' && s[i] <= 'Z') {
			for(int k = 0; k < 8; k ++) {
				int c = base[1] + s[i] - 'A';
				f[cur][c][k | op[1]] += (sum[k] - f[cur ^ 1][c][k]) % mod;	
				f[cur][c][k | op[1]] %= mod;
			}
		} else if(s[i] >= '0' && s[i] <= '9') {
			for(int k = 0; k < 8; k ++) {
				int c = base[2] + s[i] - '0';
				f[cur][c][k | op[2]] += (sum[k] - f[cur ^ 1][c][k]) % mod;	
				f[cur][c][k | op[2]] %= mod;
			}
		} else {
			for(int c = 0; c < 62; c ++) {
				for(int k = 0; k < 8; k ++) {
					if(c >= 0 && c < 26) {
						f[cur][c][k | op[0]] += (sum[k] - f[cur ^ 1][c][k]) % mod;	
						f[cur][c][k | op[0]] %= mod;
					} else if(c >= 26 && c < 52) {
						f[cur][c][k | op[1]] += (sum[k] - f[cur ^ 1][c][k]) % mod;
						f[cur][c][k | op[1]] %= mod;
					} else if(c >= 52 && c < 62) {
						f[cur][c][k | op[2]] += (sum[k] - f[cur ^ 1][c][k]) % mod;
						f[cur][c][k | op[2]] %= mod;
					}
				}
			}
		}
	}

	int ans = 0;
	for(int c = 0; c < 62; c ++) {
		ans += f[n & 1][c][7];
		ans %= mod;
	}
	// 需要注意，有负数的取模情况下得保证最终答案一定是整数
	cout << (ans % mod + mod) % mod << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}