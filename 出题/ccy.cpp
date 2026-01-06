#include<bits/stdc++.h> 
#include<string.h> 
using namespace std; 
using i64 = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q;
vector<int> a;
vector<array<int, 3>> query;

i64 random(i64 l,i64 r)
{ 
    return (rng() - l) % (r - l + 1) + l;
}

void solve1() 
{
    a.clear();
    query.clear();

    n = random(1, 1e4);
    cout << n << '\n';
    for(int i = 0; i <= n; i ++)
    {
        int x = random(1, 1e4);
        if(i != 0) cout << x << '\n';
        a.emplace_back(x);
    }

    q = random(1, 1e4);
    cout << q << '\n';
    for(int i = 0; i <= n; i ++)
    {
        int op;
        op = random(1, 2);
        int x, y;
        if(op == 1)
        {
            x = random(1, 1e5);
            y = random(1, 1e4);
            cout << op << ' ' << x << ' ' << y << '\n';
        }
        else 
        {
            if(i % 5 == 0) x = random(1, 1e9);
            else x = random(1, 1e5);
            cout << op << ' ' << x << '\n';
        }
        query.push_back({op, x, y});
    }
}

template<class T>
struct Fenwick
{
    int n;
    vector<T> a;
    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, const T &v)
    {
        for(int i = x; i <= n; i += i & -i)
            a[i] += v;
    }

    int select(const T &k)
    {
        int pos = 0;
        T cur{};
        for(int i = 1 << __lg(n); i; i >>= 1)
        {
            if(pos + i <= n && cur + a[pos + i] <= k)
            {
                pos += i;
                cur += a[pos];
            }
        }
        return pos;
    }
};

void solve2()
{
    Fenwick<int> tr(n);
    for(int i = 1; i <= n; i ++)
    {
        tr.add(i, a[i]);
    }
    for(auto &[op, x, y] : query)
    {
        if(op == 1)
        {
            tr.add(x, y);
        }
        else
        {
            cout << tr.select(x) << '\n';
        }
    }      
}

int main() 
{
    // srand(int(time(0)));
    for(int i = 1;i <= 10; i ++)
    {
        string filename1 = "";
        filename1 += to_string(i); 
        filename1 += ".in"; 
        freopen(filename1.c_str() , "w" , stdout);
        solve1();
        fclose(stdout);

        string filename2 = "";
        filename2 += to_string(i); 
        filename2 += ".out"; 
        freopen(filename2.c_str() , "w" , stdout);
        solve2();
        fclose(stdout);
    }
}

