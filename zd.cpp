#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int ne[N];

void scan(string p)
{
	int m = p.size() - 1;
	for(int i = 2, j = 0; i <= m; i ++)
	{
		while(j && p[i] != p[j + 1]) j = ne[j];
		if(p[i] == p[j + 1]) j ++;
		ne[i] = j;
	}
}

int kmp(int stt, string s, string p)
{
	int n = s.size() - 1, m = p.size() - 1;
	for(int i = stt, j = 0; i <= n; i ++)
	{
		while(j && s[i] != p[j + 1]) j = ne[j];
		if(s[i] == p[j + 1]) j ++;
		if(j == m)
		{
			return i - j + 1;
		}
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	getchar();
	string p[N];
	string k[N];
	for(int i = 1; i <= n; i ++)
	{
		getline(cin, p[i]);
		getline(cin, k[i]);
		p[i] = "#" + p[i];
	}
	string s;
	getline(cin, s);
	s = "#" + s;

	for(int i = 1; i <= n; i ++)
	{
		memset(ne, 0, sizeof ne);
		scan(p[i]);
		int len_p = p[i].size() - 1;
		int len_k = k[i].size();
		int pos = kmp(1, s, p[i]);
		while(pos)
		{
			s.replace(pos, len_p, k[i]);
			pos = kmp(pos + len_k, s, p[i]);
		}
	}

	s = s.substr(1);
	cout << s;
}