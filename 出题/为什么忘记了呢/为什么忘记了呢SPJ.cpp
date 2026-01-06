#include <bits/stdc++.h>
#define AC 0
#define WA 1
#define ERROR -1
using namespace std;
using i64 = long long;

int spj(FILE *f_in, FILE *f_user)
{
    int n;
    i64 m;
    fscanf(f_in, "%d%lld", &n, &m);
    vector<i64> a(n);

    int t = 0;
    if(m < n / 2 || (n % 2 == 0 && (m - n / 2) % 2 == 1))
    {
        int cnt = 0;
        while(fscanf(f_user, "%d", &t) != EOF)
        {
            cnt ++;
            if(cnt > 1) return WA;
        }
        if(t != -1) return WA;
        return AC;
    }
    else
    {
        for(int i = 0; i < n; i ++)
        {
            fscanf(f_user, "%lld", &a[i]);
        }

        i64 sum = 0;
        for(int i = 0; i < n; i ++)
        {
            if(a[i] < 0) return WA;
            if(i != n - 1) if(abs(a[i] - a[i + 1]) != 1) return WA;
            sum += a[i];
        }
        if(sum != m) return WA;
        return AC;
    }
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