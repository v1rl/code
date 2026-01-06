#include<bits/stdc++.h> 
#include<string.h> 
using namespace std; 
using i64 = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> res;
int idx = 0;

i64 random(i64 l,i64 r)
{ 
	return rng() % (r - l + 1) + l;
}

void solve(int &n, int &m) 
{ 
	n = random(1, 1000000);
	m = random(1, min(1000000ll, 1ll * n * (n + 1) / 2 + 1));
	cout << n << ' ' << m;
}

void solve1(int n, int m)
{
    if(m >= n + 1 && m <= 1ll * n * (n + 1) / 2 + 1)
    {
        cout << "YES" << '\n';
        int num = m - 1;
        int cnt = n;
        int base = 0;
        while(num - cnt > 0)
        {
            num -= cnt;
            cnt --;
            base ++;
        }
        for(int i = 1; i <= n; i ++)
        {
            if(base >= i) cout << i << ' ';
            else if(num > 0) cout << base + 1 << ' ', num --;
            else cout << base << ' ';
        }
    }
    else cout << "NO" << '\n';
}

int main() 
{
	// srand(int(time(0)));
	for(int i = 5;i <= 6; i ++)
	{
		int n, m;
		string filename = "";
		filename += to_string(i); 
		filename += ".in"; 
		freopen(filename.c_str() , "w" , stdout);
		solve(n, m);
		fclose(stdout);

		filename = "";
		filename += to_string(i); 
		filename += ".out";		
		freopen(filename.c_str() , "w" , stdout);
		solve1(n, m);
		fclose(stdout);
 	}
}

