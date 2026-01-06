#include<bits/stdc++.h> 
#include<string.h> 
using namespace std; 
using i64 = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> res;
int n, m;
vector<int> a;
vector<int> b;
map<int, int> mp;

i64 random(i64 l,i64 r)
{ 
    return rng() % (r - l + 1) + l;
}

void solve() 
{ 
    n = random(1, 1e5);
    m = random(1, 1e5);
    cout << n << ' ' << m << '\n';
    b.reserve(m);
    for(int i = 0; i < n; i ++)
    {
        int x = random(1, 1e9);
        while(mp.count(x)) x = random(1, 1e9);
        mp[x] ++;
        cout << x << ' ';
    }
    cout << '\n';

    map<int, int> mp1;
    for(int i = 0; i < m; i ++)
    {
        int x = random(1, 1e9);
        while(mp1.count(x)) x = random(1, 1e9);
        mp1[x] ++;
        cout << x << ' ';
        b.emplace_back(x);
    }
    cout << '\n';
}

void solve1()
{
    vector<int> ans;

    for(auto x : b)
        if(mp.count(x))
            ans.emplace_back(x); 

    sort(ans.begin(), ans.end());
    for(auto x : ans)
        cout << x << ' ';
}

int main() 
{
    // srand(int(time(0)));
    for(int i = 7;i <= 7; i ++)
    {
        int n, m;
        string filename = "";
        filename += to_string(i); 
        filename += ".in"; 
        freopen(filename.c_str() , "w" , stdout);
        solve();
        fclose(stdout);

        filename = "";
        filename += to_string(i); 
        filename += ".out";     
        freopen(filename.c_str() , "w" , stdout);
        solve1();
        fclose(stdout);

        a.clear();
        b.clear();
        mp.clear();
    }
}

