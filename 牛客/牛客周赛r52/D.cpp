#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	priority_queue<string> heap;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		string s;
		cin >> s;
		heap.push(s);
	}

	string ans = "";
	while(heap.size())
	{
		string s1 = heap.top();
		heap.pop();

		ans += s1[0];
		if(s1.size() > 1) heap.push(s1.substr(1));
	}

	cout << ans << "\n";
	return 0;
}