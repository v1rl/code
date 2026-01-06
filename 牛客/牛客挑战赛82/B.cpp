#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
有点像最长不下降子序列
但是本题针对子串，所有字符都需要选中
我们需要知道每个子串拉通后的字典序，才能更好地执行不下降划分，但暴力算显然不可取同时也没好啥办法
注意到：我们将原字符串的每个后缀都存到一个Trie树中，从Trie树根节点开始遍历的每个前缀都是一个子串
之后维护一个变量dfn，按照'a'到'z'跑一遍dfs，并在进入每个节点时让dfn自增，就得到了所有子串的字典序排名
此时，我们就可以考虑使用类似最长不下降子序列的dp
f[i]表示[1, i]的最大划分，在转移时我们遍历j -- [0, i - 1]
我们还需要判定转移是否合法，也是就是比较f[j]中最后一个子串的dfn和子串s[j + 1, i]的大小关系
这也就需要我们在维护f[i]属性时额外存最后的dfn，同时需要我们知道任意原字符串任意范围子串s[l, r]的dfn大小

我们可以在建立Trie的时候一个存二元组的vector，表示根节点到当前节点的子串和原子串中哪些范围的子串相同
并在之后dfs的过程中，根据这个vector维护一个二维数据g[l][r]表示子串s[l, r]的dfn

Trick：对字符串的所有后缀建一个Trie树，原字符串中所有子串，可转换为该后缀Trie树的所有前缀，并可以在建Trie树时与子串
处在原字符串中的位置对应

后缀Trie树 + dfs + dp
*/

struct Trie {
	int n;
	int idx = 0;
	int dfn = 0;
	vector<array<int, 26>> trie;
	vector<vector<array<int, 2>>> pr;

	Trie(int n_) : n(n_), trie(n * 26 + 1), pr(n * 26 + 1) {};

	void insert(int stt, string s) {
		int p = 0;
		for(int i = 0; i < s.size(); i ++) {
			int ch = s[i] - 'a';
			if(!trie[p][ch]) {
				trie[p][ch] = ++ idx;
			}
			p = trie[p][ch];
			pr[p].push_back({stt, stt + i});
		}
	}

	void dfs(int p, auto& g) {
		dfn ++;
		for(auto &[l, r] : pr[p]) {
			g[l][r] = dfn;
		}
		for(int ch = 0; ch < 26; ch ++) {
			if(trie[p][ch]) {
				dfs(trie[p][ch], g);
			}
		}
	}

};

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	Trie trie(n * n);
	s = s.substr(0, n);
	vector g(n, vector(n, 0));
	for(int i = 0; i < s.size(); i ++) {
		trie.insert(i, s.substr(i));
	}


	trie.dfs(0, g);
	// cerr << 'h';

	// for(int i = 0; i < n; i ++) {
	// 	for(int j = 0; j < n; j ++) {
	// 		cerr << g[i][j] << " \n"[j == n - 1];
	// 	}
	// }

	vector<array<int, 2>> f(n);
	for(int i = 0; i < n; i ++) {
		auto &[v, dfn] = f[i];
		v = 1, dfn = g[0][i];
		for(int j = 0; j < i; j ++) {
			auto &[lv, ldfn] = f[j];
			if(ldfn <= g[j + 1][i]) {
				if(lv + 1 > v || (lv + 1 == v && g[j + 1][i] < dfn)) {
					v = lv + 1;
					dfn = g[j + 1][i];
				}
			}
		}
	}

	// for(int i = 0; i < n; i ++) {
	// 	cout << f[i][0] << '\n';
	// }

	cout << f[n - 1][0] << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}