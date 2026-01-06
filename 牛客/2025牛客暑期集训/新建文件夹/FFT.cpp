#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
#define int long long

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

// 这里插入你提供的Polynomial类定义

int main() {
    // 示例1: 计算 (1 + 2x + 3x^2) * (4 + 5x + 6x^2)
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};
    
    // 扩展数组长度为2的幂次方，至少为a.size()+b.size()-1
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    a.resize(n);
    b.resize(n);
    
    // 创建多项式对象并执行FFT
    Polynomial pa(a);
    Polynomial pb(b);
    
    // 点值相乘
    vector<Polynomial::Complex> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = pa.c[i] * pb.c[i];
    }
    
    // 逆FFT转换回系数表示
    Polynomial::fft(result, n, -1);
    
    // 输出结果
    cout << "多项式乘法结果: ";
    for (int i = 0; i < a.size() + b.size() - 1; i++) {
        cout << round(result[i].x) << " ";  // 四舍五入，因为FFT可能有浮点误差
    }
    cout << endl;
    // 预期输出: 4 13 28 27 18
    
    // 示例2: 计算 (1 + x) * (1 - x) = 1 - x^2
    vector<int> c = {1, 1, 0, 0};  // 1 + x
    vector<int> d = {1, -1, 0, 0};  // 1 - x
    
    Polynomial pc(c);
    Polynomial pd(d);
    
    vector<Polynomial::Complex> result2(n);
    for (int i = 0; i < n; i++) {
        result2[i] = pc.c[i] * pd.c[i];
    }
    
    Polynomial::fft(result2, n, -1);
    
    cout << "另一个多项式乘法结果: ";
    for (int i = 0; i < c.size() + d.size() - 1; i++) {
        cout << round(result2[i].x) << " ";
    }
    cout << endl;
    // 预期输出: 1 0 -1 0
    
    return 0;
}