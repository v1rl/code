#include <bits/stdc++.h>
#define AC 0
#define WA 1
#define ERROR -1
using i64 = long long;
using namespace std;

int spj(FILE *f_in, FILE *f_user)
{

    int n, m;
    fscanf(f_in,"%d%d%d",&n, &m);

    char s[1010];
    fscanf(f_in, "%s", s);
    if(m >= n + 1 && m <= 1ll * n * (n + 1) / 2 + 1)
    {
        if(strcmp(s, "YES") != 0) return WA;
        vector<i64> a(n);
        for(int i = 0; i < n; i ++)
        {
            fscanf(f_user, "%lld", &a[i]);
        }
        i64 sum = 0;
        for(int i = 0; i < n; i ++)
        {
            if(a[i] > i + 1) return WA;
            if(a[i] <= 0) return WA;
            sum += a[i];
        }
        if(sum != m - 1) return WA; 
    }
    else
    {
        if(strcmp(s, "NO") != 0) return WA; 
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
