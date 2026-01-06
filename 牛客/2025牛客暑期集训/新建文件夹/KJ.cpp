#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
#define int long long

// 移位不分奇偶
// 进位分奇偶
// 当前位的两个可以抵下一位的一个，若下一位为0，则下一位和下两位都加上1，当前位的四个可以加下两位的一个

struct Polynomial {
    constexpr static double PI = acos(-1);
    struct Complex {
        double x, y;
        Complex(double _x = 0.0, double _y = 0.0) {
            x = _x;
            y = _y;
        }
        Complex operator-(const Complex &rhs) const {
            return Complex(x - rhs.x, y - rhs.y);
        }
        Complex operator+(const Complex &rhs) const {
            return Complex(x + rhs.x, y + rhs.y);
        }
        Complex operator*(const Complex &rhs) const {
            return Complex(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
        }
    };
    vector<Complex> c;
    Polynomial(vector<int> &a) {
        int n = a.size();
        c.resize(n);
        for (int i = 0; i < n; i++) {
            c[i] = Complex(a[i], 0);
        }
        fft(c, n, 1);
    }
    void change(vector<Complex> &a, int n) {
        for (int i = 1, j = n / 2; i < n - 1; i++) {
            if (i < j) swap(a[i], a[j]);
            int k = n / 2;
            while (j >= k) {
                j -= k;
                k /= 2;
            }
            if (j < k) j += k;
        }
    }
    void fft(vector<Complex> &a, int n, int opt) {
        change(a, n);
        for (int h = 2; h <= n; h *= 2) {
            Complex wn(cos(2 * PI / h), sin(opt * 2 * PI / h));
            for (int j = 0; j < n; j += h) {
                Complex w(1, 0);
                for (int k = j; k < j + h / 2; k++) {
                    Complex u = a[k];
                    Complex t = w * a[k + h / 2];
                    a[k] = u + t;
                    a[k + h / 2] = u - t;
                    w = w * wn;
                }
            }
        }
        if (opt == -1) {
            for (int i = 0; i < n; i++) {
                a[i].x /= n;
            }
        }
    }
};

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a(s1.size()), b(s2.size());
    for(int i = 0; i < s1.size(); i ++) {
        a[i] = s1[i] - '0';
    }
    for(int i = 0; i < s2.size(); i ++) {
        b[i] = s2[i] - '0';
    }

    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;

    a.resize(n);
    b.resize(n);
    Polynomial pa(a);
    Polynomial pb(b);

    vector<Polynomial::Complex> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = pa.c[i] * pb.c[i];
    }

    pa.fft(result, n, -1);

    // cerr << 'h';
    int len = s1.size() + s2.size() + 10;
    vector<int> num(len);
    for (int i = 0; i < s1.size() + s2.size(); i ++) {
        num[i + 1] = result[i].x + 0.5;
    }

    reverse(num.begin() + 1, num.begin() + s1.size() + s2.size());

    for(int i = 1; i < len; i ++) {
        // cerr << i << ' ' << num[i] << "\n";
        int x;
        if(num[i] & 1) {
            x = num[i] - 1;
            num[i] = 1;
        } else {
            x = num[i];
            num[i] = 0;
        }

        int t = x / 4;
        if(t) {
            num[i + 4] += t;
            x %= 4;            
        }

        if(x == 0) continue;

        if(num[i + 2] > 0) {
            num[i + 2] --;
        } else {
            num[i + 2] ++;
            num[i + 4] ++;
        }
    }

    bool f = false;
    for(int i = len - 1; i >= 1; i --) {
        if(num[i] == 1) {
            f = true;
        }
        if(num[i] == 0 && !f) {
            continue;
        }
        cout << num[i];
    }

    if(!f) {
        cout << 0;
    }

    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}