#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int x, k;
        cin >> x >> k;
        if(k >= lowbit(x)) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }
}   
