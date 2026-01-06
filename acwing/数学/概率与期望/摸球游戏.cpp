#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

// https://pintia.cn/problem-sets/1901208334336921600/exam/problems/type/7?problemSetProblemId=1901208334366281741

/*
已知E(0), 求E(n)
根据题目，令E(k)等于在k次操作后白球个数的期望，令Pr等于抽到黑球的概率
那么不难得出E(k + 1) - E(k) = Pr
因为总球数为a+b不变，我们可以得到Pr = (a + b - E[k]) / (a + b)
联立这两个式子，我们就可以得到白球个数期望的递推式，即E(k + 1) = c * E(k) + 1，其中c = (a + b - 1) / (a + b)，E(0) = a
显然，在本题复杂度上我们无法O(n)递推求解，所以我们需要推公式得到E(k)与E(0)的通解
不会递推没关系，我们多写几项找找规律
E(1) = c * a + 1
E(2) = c * E(1) + 1 = c * (c * a + 1) + 1 = c^2 * a + c + 1
E(3) = c * E(2) + 1 = c * (c^2 * a + c + 1) + 1 = c^3 * a + c^2 + c + 1
...
注意到，后面的几项是等比数列，利用等比数列求和公式，我们最终便得到了这个式子：
E(k) = c^k * a + (1 - c^k) / (1 - c)
化简后，我们得到这个式子：
E(k) = a + b - b * c^k
于是，带入 n 求解即可

Trick：对于已知首项的期望问题，可以尝试寻找期望的递推式，并在递推求解超时的情况下尝试求解线性递推式
建议像上面一样把系数c单独写，否则式子容易过于臃肿
*/

i64 qmi(i64 a, i64 b) {
	i64 res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	int a, b, n;
	cin >> a >> b >> n;
	int ans = ((a + b) - 1ll * b * qmi((1 - qmi(a + b, mod - 2)), n) % mod) % mod;
	cout << (ans + mod) % mod << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	// t = 1;
	while(t --) {
		solve();
	}
}