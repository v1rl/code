#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/


void solve() {
    int n;
    cin >> n;

    int l = 1, r = n;
    int sump = 0, suma = 0;
    cout << 2 << ' ' << 1 << ' ' << n << endl;
    cin >> suma;
    sump = n * (n + 1) / 2;
    while(l < r) {
        int mid = l + r >> 1;
        int lps = 0, rps = 0, las = 0, ras = 0;
        cout << 1 << ' ' << l << ' ' << mid << endl;
        cin >> lps;
        rps = sump - lps;
        cout << 2 << ' ' << l << ' ' << mid << endl;
        cin >> las;
        ras = suma - las;

        // cout << suma << ' ' << sump << '\n';

        if(lps == las) {
            l = mid + 1;
            suma -= las;
            sump -= lps;
            continue;
        } else if(rps == ras) {
            suma -= ras;
            sump -= rps;
            r = mid;
            continue;
        } else {
            int dl = las - lps, dr = ras - rps;
            cout << '!' << ' ' << mid - dl + 1 << ' ' << mid + dr << endl;
            return;
        }
    }
    cout << '!' << ' ' << l << ' ' << r << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    // cout << (1 << 13) << '\n';
    while(t --) {
        solve();
    }
    return 0;
}