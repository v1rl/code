#include <bits/stdc++.h>
#define AC 0
#define WA 1
#define ERROR -1
using namespace std;

int spj(FILE *f_in, FILE *f_user)
{
    int n, m, l;
    fscanf(f_in,"%d%d%d",&n, &m, &l);
    vector<int> v(n + 1);
    vector<int> us_ans(n);
    for(int i = 1; i <= n; i ++) fscanf(f_in, "%d", &v[i]);
    vector<vector<int>> f(n + 1, vector<int>(1001, -1e9));
    for(int i = 0; i <= m; i ++) f[0][i] = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j <= l; j ++)
        {
            f[i][j] = max(f[i - 1][j], f[i - 1][max(0, j - v[i])] + 1);
        }
    }

    int ac_num = f[n][0];
    int us_num;
    fscanf(f_user, "%d", &us_num);
    for(int i = 0; i < us_num; i ++) fscanf(f_user, "%d", &us_ans[i]);

    if(us_num != ac_num) return WA;
    for(int i = 0; i < us_num; i ++)
    {
        if(i && us_ans[i] <= us_ans[i - 1]) return WA;
        if(us_ans[i] <= 0 && us_ans[i] > n) return WA;
        m = min(m + v[us_ans[i]], l);
        if(m < 0) return WA;
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