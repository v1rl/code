#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

map<char, int> mp = {
    {'O', 7},
    {'B', 6},
    {'A', 5},
    {'F', 4},
    {'G', 3},
    {'K', 2},
    {'M', 1}
};

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    int n1 = mp[s1[0]] * 10 + 10 - (s1[1] - '0');
    int n2 = mp[s2[0]] * 10 + 10 - (s2[1] - '0');
    if(n1 == n2) {
        cout << "same" << '\n';
    } else if(n1 > n2) {
        cout << "hotter" << '\n';
    } else {
        cout << "cooler" << '\n';
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
