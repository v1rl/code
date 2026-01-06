#include <bits/stdc++.h>
#define AC 0
#define WA 1
#define ERROR -1
using namespace std;

int spj(FILE *f_in, FILE *f_user)
{
    int n, m;
    fscanf(f_in,"%d%d",&n, &m);
    vector<int> a(m);
    vector<int> st(m);
    vector<int> ans;
    for(int i = 0; i < m; i ++) fscanf(f_in, "%d", &a[i]);

    
    bool f = false;
    auto dfs = [&](auto &&self, int res, int u)->bool
    {
        if(u == m)
        {
            for(auto i : ans) cout << i + 1 << ' ';
            f = true;
            return true;
        }
        for(int i = 0; i < m; i ++)
        {
            if(st[i]) continue;
            if(res + a[i] > n) continue;
            st[i] = true;
            ans.emplace_back(i);
            if(self(self, max(res + a[i], 0), u + 1)) return true;
            ans.pop_back();
            st[i] = false;
        }
        return false;
    };

    dfs(dfs, 0, 0);
    if(!f)
    {
        int num;
        fscanf(f_user, "%d", &num);
        if(num != -1) return WA; 
    }    
    else
    {
        vector<int> ans(m);
        for(int i = 0; i < m; i ++) fscanf(f_user, "%d", &ans[i]);
        vector<int> st(m);
        int sum = 0;
        for(int i = 0; i < m; i ++)
        {
            ans[i] --;
            if(ans[i] < 0 || ans[i] > m) return WA;
            if(st[ans[i]]) return WA;
            st[ans[i]] = true;
            if(sum + a[ans[i]] > n) return WA;
            sum += a[ans[i]];
            if(sum < 0) sum = 0;
        }
    }
    return AC;
}

void close_file(FILE *f)
{
    if(f != NULL){
        fclose(f);
    }
}

int main(int argc, char *args[]){
    FILE *input = NULL, *user_output = NULL;
    int result;
    if(argc != 3){
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }
    input = fopen(args[1], "r");
    user_output = fopen(args[2], "r");
    if(input == NULL || user_output == NULL){
        printf("Failed to open output file\n");
        close_file(input);
        close_file(user_output);
        return ERROR;
    }

    result = spj(input, user_output);
    printf("result: %d\n", result);
    
    close_file(input);
    close_file(user_output);
    return result;
}