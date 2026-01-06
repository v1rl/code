#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

istream &operator>>(istream &is, i128 &x) 
{
    string s;
    is >> s;
    bool neg = false;
    x = 0;
    for(auto c : s) 
    {
        if (c == '-') neg = true;
        else x = x * 10 + (c - '0');
    }
    if(neg) x = -x;
    return is;
}

ostream &operator<<(ostream &os, i128 x)
{
    if(x == 0) return os << 0;
    string s, t;
    if(x < 0) x = -x, t = "-";
    while(x) s += '0' + x % 10, x /= 10;
    reverse(s.begin(), s.end());
    // os << t << s;
    return os << t << s;
}

inline i128 to_i128(string s)
{
    i128 m = 0;
    for(auto c : s){
        m *= 10;
        m += s[i] - 48;
    }
    return m;
}

int main()
{
    i128 a;
    cin >> a;
    cout << a;
}
