#include<bits/stdc++.h> 
#include<fstream>
using namespace std; 
using i64 = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() 
{
        ifstream fcin;
        string filename1 = "1000.txt";
        fcin.open(filename1);
        int n;
        fcin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i ++)
            fcin >> a[i];
        fcin.close();

        string filename2 = "P3332_2.out";
        fcin.open(filename2);
        fcin >> n;
        vector<int> b(n + 1);
        for(int i = 1; i <= n; i ++)
            fcin >> b[i];
        fcin.close();

        for(int i = 1; i <= n; i ++)
        {
            if(a[i] != b[i])
            {
                cout << i << '\n';
            }
        }
}

