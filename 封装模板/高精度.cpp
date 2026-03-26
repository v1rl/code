#include<bits/stdc++.h>
using namespace std;
const int M = 1e3 + 10;

struct hh
{
    int a[M], siz = 0;
    bool f = false;

    hh(string t = "")
    {
        memset(a, 0, sizeof a);
        siz = t.size();
        for(int i = 1, j = t.size() - 1; i <= siz; i ++, j --)
        {
            a[i] = t[j] - '0';
        }
    }

    void jw()
    {
        for(int i = 1; i <= siz; i ++) a[i + 1] += a[i] / 10, a[i] %= 10;
        if(a[siz + 1]) siz ++;
    }

    hh operator +(hh x)
    {
        hh s; s.siz = max(siz, x.siz);
        for(int i = 1; i <= s.siz; i ++) s.a[i] = a[i] + x.a[i];
        s.jw();
        return s;
    }

    hh operator *(hh x)
    {
        hh s; s.siz = siz + x.siz - 1;
        for(int i = 1; i <= siz; i ++)
            for(int j = 1; j <= x.siz; j ++)
                s.a[i + j - 1] += a[i] * x.a[j];
        s.jw();
        return s;
    }

    hh operator -(hh x)
    {
        hh s; s.siz = max(siz, x.siz);
        if(*this < x) swap(*this, x), s.f = true;
        // if(swap(siz, x.siz), swap(a, x.a);
        for(int i = 1; i <= s.siz; i ++) s.a[i] = a[i] - x.a[i];
        for(int i = 1; i <= s.siz; i ++) if(s.a[i] < 0) s.a[i] += 10, s.a[i + 1] --;
        while(s.siz > 1 && s.a[s.siz] == 0) s.siz --;
        return s; 
    }

    hh operator /(int x)
    {
        hh s; s.siz = 1;
        for(int i = siz, t = 0; i; i --)
        {
            t = t * 10 + a[i];
            s.a[i] = t / x;
            t %= x;
            if(s.a[i]) s.siz = max(s.siz, i);
        }
        return s;
    }

    bool operator <(hh x) const
    {
        if(siz != x.siz) return siz < x.siz;
        for(int i = siz; i; i --)
            if(a[i] != x.a[i]) return a[i] < x.a[i];
        return 0;
    }

    void print()
    {
        for(int i = siz; i; i --) cout << a[i];
        cout << '\n';
    }
};

ostream &operator<<(ostream &o, const hh &a) {
    if(a.f) cout << '-'; 
    for (int i = a.siz; i; i --)
        o << a.a[i];

    return o;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    hh x(a), y(b), z(c), ans;
    
    cout << x << '\n';
    cout << y << '\n';
    cout << z << '\n';
    // ans = x / 5;
    // ans = x * y;
    // ans = x - hh("1000");
    ans = y / 90;
    // ans = x + y;
    cout << ans << '\n';
}