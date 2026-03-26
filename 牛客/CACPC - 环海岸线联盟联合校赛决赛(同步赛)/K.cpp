#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

vector<int> zFunction(string &s) {
    int n = s.size();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; i ++) {
        if(i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i] ++;
        }

        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void solve() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    s1 = s3 + '#' + s1;
    reverse(s2.begin(), s2.end());
    reverse(s3.begin(), s3.end());

    s2 = s3 + '#' + s2;

    // cout << s1 << '\n' << s2 << '\n';

    vector<int> a = zFunction(s1), b = zFunction(s2);
    int mx1 = 0, mx2 = 0;
    // cout << a.size() << ' ' << b.size() << '\n';
    // cout << s3.size() << '\n';

    for(int i = s3.size() + 1; i < a.size(); i ++) {
        // cout << i << ' ' << a[i] << '\n';
        mx1 = max(mx1, a[i]);
    }
    for(int i = s3.size() + 1; i < b.size(); i ++) {
        mx2 = max(mx2, b[i]);
    }


    if(mx1 + mx2 >= s3.size()) {
        cout << "qiang" << '\n';
    } else {
        cout << "ruo" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
