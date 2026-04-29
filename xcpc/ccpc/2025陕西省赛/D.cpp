#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9 + 10;

struct Node {
    double sum, cur;
};

const double EPS = 1e-8;

int sgn(double x) {
    if (fabs(x) < EPS) return 0;
    return x < 0 ? -1 : 1;
}

void solve() {
    int n;
    cin >> n;
    double res;
    cin >> res;

    vector<double> add;
    vector<double> mul;
    for(int i = 0; i < n; i ++) {
        char op;
        double x;
        cin >> op >> x;
        if(op == '+') {
            add.emplace_back(x); 
        } else {
            mul.emplace_back(x);
        }
    }


    sort(add.begin(), add.end(), greater());
    sort(mul.begin(), mul.end(), greater());
    int A = add.size(), B = mul.size();

    auto work = [&](vector<Node> &a) -> void {
        sort(a.begin(), a.end(), 
            [&](auto &x, auto &y) {
                if(sgn(x.sum - y.sum) != 0) {
                    return x.sum > y.sum;
                }
                return x.cur > y.cur;
            });

        vector<Node> ne;
        double Cmx = -1.0;
        for(auto &[sum, cur] : a) {
            if(sgn(cur - Cmx) > 0) {
                ne.push_back({sum, cur});
                Cmx = cur;
            }
        }
        a = move(ne);
    };

    vector<Node> f[A + 1][B + 1];
    f[0][0].push_back({0.0, res});


    for(int i = 0; i <= A; i ++) {
        for(int j = 0; j <= B; j ++) {
            work(f[i][j]);

            if(i < A) {
                for(auto [sum, cur] : f[i][j]) {
                    double ncur = cur + add[i];
                    double nsum = sum + ncur;
                    f[i + 1][j].push_back({nsum, ncur});
                }
            }

            if(j < B) {
                for(auto [sum, cur] : f[i][j]) {
                    double ncur = cur * mul[j];
                    double nsum = sum + ncur;
                    f[i][j + 1].push_back({nsum, ncur});
                }
            }
        }
    }

    double ans = f[A][B][0].sum;
    cout << fixed << setprecision(10);
    cout << ans / n << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
