#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
显然，如果只是单纯的每次只考虑位置+1，解空间中会出现重复的状态
为避免重复，我们引入"当前正在维护的值"这一变量到heap的存储中
因为每次变化带给sum的扰动来源并不仅仅是变化值本身，我们仍需要存下全部的三个值
每次转移时，我们只考虑转移当前维护的值
然后，考虑当前维护的值发生递进变化，因为三个选择的值给sum带来的影响并不等价，我们要维护的是有序集（维护新值时从0开始）
对于有序集，后方的变化和当前下一位的变化是不等价的，所以递进变化时要将后面的所有值都考虑到，而不是只考虑下一个
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<i64> a(n), b(n), c(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> c[i];
    }
    sort(a.begin(), a.end(), greater());
    sort(b.begin(), b.end(), greater());
    sort(c.begin(), c.end(), greater());

    priority_queue<tuple<i64, int, int, int, int>> heap;
    heap.push({a[0] * b[0] + b[0] * c[0] + c[0] * a[0], 0, 0, 0, 0});
    for(int i = 0; i < k - 1; i ++) {
        auto [sum, x, y, z, cur] = heap.top();
        heap.pop();

        if(cur == 0 && x + 1 < n) {
            heap.push({a[x + 1] * b[y] + b[y] * c[z] + c[z] * a[x + 1], x + 1, y, z, cur});
        } else if(cur == 1 && y + 1 < n) {
            heap.push({a[x] * b[y + 1] + b[y + 1] * c[z] + c[z] * a[x], x , y + 1, z, cur});
        } else if(cur == 2 && z + 1 < n) {
            heap.push({a[x] * b[y] + b[y] * c[z + 1] + c[z + 1] * a[x], x, y, z + 1, cur});
        }
        while(cur != 2) {
            cur ++;
            if(cur == 0 && x + 1 < n) {
                heap.push({a[x + 1] * b[y] + b[y] * c[z] + c[z] * a[x + 1], x + 1, y, z, cur});
            } else if(cur == 1 && y + 1 < n) {
                heap.push({a[x] * b[y + 1] + b[y + 1] * c[z] + c[z] * a[x], x , y + 1, z, cur});
            } else if(cur == 2 && z + 1 < n) {
                heap.push({a[x] * b[y] + b[y] * c[z + 1] + c[z + 1] * a[x], x, y, z + 1, cur});
            }
        }
    }

    auto t = heap.top();
    cout << get<0>(t) << '\n';
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
