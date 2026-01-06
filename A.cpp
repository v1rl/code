#include<bits/stdc++.h>
using namespace std;

struct Node {
	int acc = 0;
	int time = 0;
	int macc = 0;
	int mtime = 0;
	bool f = false;
	unordered_set<int> st, mst;
	unordered_map<int, int> fs;
	int total = 0;
};

struct dat {
	string s;
	char p;
	int time;
	string op;
};

void solve() {
	int n;
	cin >> n;
	map<string, Node> mp;


	vector<dat> q;
	q.reserve(n);
	for(int i = 1; i <= n; i ++) {
		string s, op;
		char p;
		int time;
		cin >> s >> p >> time >> op;
		q.push_back({s, p, time, op});
	}

	sort(q.begin(), q.end(), 
		[&](auto x, auto y) {
			return x.time < y.time;
		});

	for(auto &[s, p, time, op] : q) {
		if(op == "Accepted") {
			int ch = p - 'A';
			if(mp[s].st.count(ch)) {
				continue;
			}
			mp[s].st.insert(ch);
			mp[s].acc ++;
			mp[s].time += time;
			mp[s].time += mp[s].fs[ch];

			// mp[s].total -= mp[s].fs[ch];
		} else if(op == "Rejected") {
			int ch = p - 'A';
			if(mp[s].st.count(ch)) {
				continue;
			}
			mp[s].fs[ch] += 20;
			// mp[s].total += 20;
		} else {
			int ch = p - 'A';
			if(mp[s].mst.count(ch) || mp[s].st.count(ch)) {
				continue;
			}
			// cerr << s << '\n';
			mp[s].mst.insert(ch);
			mp[s].macc ++;
			mp[s].mtime += time;
			mp[s].f = true;
			mp[s].total += mp[s].fs[ch];
		}
	}

	// cerr << mp["3NhYHv8w"].f << '\n';

	int cpacc = 0, cptime = 1e9;
	string cpname;
	for(auto &[s, cur] : mp) {
		// cerr << s << ' ' << cur.time << '\n';
			// cerr << s << '\n';
		if(cpacc < cur.acc) {
			cpacc = cur.acc;
			cptime = cur.time;
			cpname = s;
		} else if(cpacc == cur.acc) {
			if(cptime > cur.time) {
				cptime = cur.time;
				cpname = s;
			}
		}
	}

	vector<string> ans;
	// cout << ans.size() << '\n';
	// cerr << cpacc << '\n';

	for(auto &[s, cur] : mp) {
		// cerr << s << ' ' << cur.acc << ' ' << cur.macc << '\n';
		if(cur.acc + cur.macc > cpacc) {
			ans.emplace_back(s);
		} else if(cur.acc + cur.macc == cpacc) {
			if(cur.time + cur.mtime + cur.total <= cptime) {
				ans.emplace_back(s);
			}
		}
	}

	sort(ans.begin(), ans.end());
	for(auto c : ans) {
		cout << c << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t --) {
		solve();
	}
}