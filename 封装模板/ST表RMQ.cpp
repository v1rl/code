    #include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

template<class T>
struct RMQ {
    int n;
    vector<vector<T>> st;
    vector<int> lg;

    RMQ(vector<T> &a) {
        init(a);
    }

    void init(vector<T> &a) {
        n = a.size() + 1;
        lg.assign(n + 1, 0);
        for(int i = 2; i <= n; i ++) {
            lg[i] = lg[i >> 1] + 1;
        }

        int K = lg[n];
        st.assign(n + 1, vector<T>(K + 1, 0));

        for(int i = 1; i <= n; i ++) {
            st[i][0] = a[i];
        }
        for(int j = 1; j <= K; j ++) {
            int len = 1 << j;
            int half = len >> 1;
            for(int i = 1; i + len - 1 <= n; i ++) {
                st[i][j] = max(st[i][j - 1], st[i + half][j - 1]);
            }
        }
    }

    T ask(int l, int r) {
        int j = lg[r - l + 1];
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    RMQ<int> rmq(a);
    while(q --) {
        int l, r;
        cin >> l >> r;
        if(l == r) {
            cout << 0 << '\n';
            continue;
        }
        cout << rmq.ask(l, r) << '\n';
    }
}