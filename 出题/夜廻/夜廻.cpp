#include<bits/stdc++.h> 
#include<string.h> 
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

i64 random(i64 l,i64 r)
{ 
    return rng() % (r - l + 1) + l;
}

void solve() 
{ 
    vector<int> res;
    int idx = 0;
    int n = random(1, 10000);
    int m = random(n - 1, 100000);
    int k = random(min(2000, n), min(3000, n));
    res.reserve(n);
    cout << n << ' ' << m << ' ' << k << '\n';

    vector<vector<PII>> adj(n + 1);
    vector<int> st(n + 1);
    for(int i = 0; i < k; i ++)
    {
        int cnt = random(1, n);
        while(st[cnt]) cnt = random(1, n);
        st[cnt] = true;
        adj[0].emplace_back(cnt, 0);
        cout << cnt << ' ';
    }

    cout << '\n';

    res.emplace_back(++ idx);
    while(idx < n)
    {
        int x = res[random(0, idx - 1)];
        int w = random(1, 100000);
        idx ++;
        adj[x].emplace_back(idx, w);
        adj[idx].emplace_back(x, w);
        res.emplace_back(idx);
        cout << x << ' ' << idx << ' ' << w << '\n';
    }



    for(int i = 0; i < m - n + 1; i ++)
    {
        int x = res[random(0, idx - 1)];
        int y = res[random(0, idx - 1)];
        int w = random(1, 100000);
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
        cout << x << ' ' << y << ' ' << w << '\n';
    }   


    auto dijkstra = [&](int S)
    {
        vector<int> dist(n + 1, 1e9);
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        heap.push({0, S});
        while(heap.size())
        {
            auto [d, x] = heap.top();
            heap.pop();
            if(dist[x] != 1e9) continue;
            dist[x] = d;
            for(auto [y, w] : adj[x])
            {
                if(dist[x] + w < dist[y])
                    heap.push({dist[x] + w, y});
            }
        }
        return dist;
    };

    int stt = random(1, n);
    int edd = random(1, n);
    cout << stt << ' ' << edd << ' ' << '\n';
    vector<int> dist1 = dijkstra(0);
    vector<int> dist2 = dijkstra(stt);

    cout << min(dist1[stt] + dist1[edd], dist2[edd]) << '\n';
}

int main() 
{
    // srand(int(time(0)));
    for(int i = 9;i <= 9; i ++)
    {
        string filename = "";
        filename += to_string(i); 
        filename += ".in"; 
        freopen(filename.c_str() , "w" , stdout);
        solve();
        fclose(stdout);
    }
}

