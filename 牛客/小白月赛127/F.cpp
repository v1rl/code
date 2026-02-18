#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
四的倍数的奇数倍
偶数的偶数倍

奇数只能和四的倍数在一起

4 1 3 5 2 6
奇数节点要么向下连4的倍数，要么作为叶子节点
非四倍数偶数节点只能

以非四倍数偶数为根节点
先处理所有非四倍数偶数
然后连接四倍数
然后连接奇数
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(3);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if(x % 4 == 0) {
            a[0].emplace_back(i);
        } else if(x % 2 == 0) {
            a[1].emplace_back(i);
        } else {
            a[2].emplace_back(i);
        }
    }

    if(n == 1) {
        cout << 1 << '\n';
        return;
    }

    vector<array<int, 2>> ans;

    queue<int> q;
    if(a[1].size()) {
        q.push(a[1].back());
        // cout << a[1].back();
        ans.push_back({a[1].back(), -1});
        a[1].pop_back();
        while(a[1].size()) {
            int x = q.front();
            q.pop();
            for(int i = 0; i < k; i ++) {
                // cout << x << ' ' << a[1].back() << '\n';
                ans.push_back({x, a[1].back()});
                q.push(a[1].back());
                a[1].pop_back();
                if(a[1].empty()) {
                    break;
                }         
            }
        }
    }


    if(q.size()) {
        int x = q.front();
        q.pop();
        if(a[0].size()) {
            // cout << x << ' ' << a[0].back();
            ans.push_back({x, a[0].back()});
            x = a[0].back();
            a[0].pop_back();
        } else {
            if(a[2].size()) {
                cout << -1 << '\n';
                return;
            }
        }
        int ne = x;
        while(a[2].size()) {
            for(int i = 0; i < k; i ++) {
                // cout << x << ' ' << a[2].back();
                ans.push_back({x, a[2].back()});
                ne = a[2].back();
                a[2].pop_back();
                if(a[2].empty()) {
                    break;
                }
            }
            if(a[2].empty()) {
                break;
            }
            if(a[0].empty()) {
                cout << -1 << '\n';
                // cerr << 'h';
                return;
            }
            // cout << ne << ' ' << a[0].back();
            ans.push_back({ne, a[0].back()});
            x = a[0].back();
            a[0].pop_back();
        }
        if(a[0].size()) {
            while(q.size()) {
                q.pop();
            }
            q.push(ne);
            while(a[0].size()) {
                x = q.front();
                q.pop();

                for(int i = 0; i < k; i ++) {
                    // cout << x << ' ' << a[0].back();
                    ans.push_back({x, a[0].back()});
                    q.push(a[0].back());
                    a[0].pop_back();
                    if(a[0].empty()) {
                        break;
                    }
                }
            }
        }
    } else {
        if(a[2].size()) {
            int x = a[2].back();
            a[2].pop_back();
            // cout << x << '\n';
            ans.push_back({x, -1});
            if(a[0].size()) {
                // cout << x << ' ' << a[0].back();
                ans.push_back({x, a[0].back()});
                x = a[0].back();
                a[0].pop_back();
            } else {
                if(a[2].size()) {
                    cout << -1 << '\n';
                    return;
                }
            }
            int ne = x;

            while(a[2].size()) {
                for(int i = 0; i < k; i ++) {
                    // cout << x << ' ' << a[2].back();
                    ans.push_back({x, a[2].back()});
                    ne = a[2].back();
                    a[2].pop_back();
                    if(a[2].empty()) {
                        break;
                    }
                }
                if(a[2].empty()) {
                    break;
                }
                if(a[0].empty()) {
                    cout << -1 << '\n';
                    // cerr << 'h';
                    return;
                }
                // cout << ne << ' ' << a[0].back();
                ans.push_back({ne, a[0].back()});
                x = a[0].back();
                a[0].pop_back();
            }

            if(a[0].size()) {
                while(q.size()) {
                    q.pop();
                }
                q.push(ne);
                while(a[0].size()) {
                    x = q.front();
                    q.pop();

                    for(int i = 0; i < k; i ++) {
                        // cout << x << ' ' << a[0].back();
                        ans.push_back({x, a[0].back()});
                        q.push(a[0].back());
                        a[0].pop_back();
                        if(a[0].empty()) {
                            break;
                        }
                    }
                }
            }
        } else {
            while(q.size()) {
                q.pop();
            }
            int x = a[0].back();
            ans.push_back({x, -1});
            q.push(x);
            a[0].pop_back();
            while(a[0].size()) {
                x = q.front();
                q.pop();

                for(int i = 0; i < k; i ++) {
                    // cout << x << ' ' << a[0].back();
                    ans.push_back({x, a[0].back()});
                    q.push(a[0].back());
                    a[0].pop_back();
                    if(a[0].empty()) {
                        break;
                    }
                }
            }
        }
    }

    for(auto [x, y] : ans) {
        if(y != -1) {
            cout << x << ' ' << y << '\n';
        } else {
            cout << x << '\n';
        }
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
