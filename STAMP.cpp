#include <bits/stdc++.h>

using namespace std;

long long int a[1000000], dp[10000][10000];

// long long int factorial(long long int n)
// {
//     int f = 1;
//     for(int i = 1; i <= n; i++)
//         f *= i;
//     return f;
// }

// long long int C(long long int k, int n)
// {
//     return factorial(n) / (factorial(k) * factorial(n - k));
// }



int main()
{
    int n, m, p;
    long long k;
    
    freopen("STAMP.inp", "r", stdin);
    freopen("STAMP.out", "w", stdout);  

    cin >> n >> m >> k >> p;

    // long long sum = 0;
    
    // for(long long int i = 0; i <= k / 2; ++i)
    // {
    //     sum += (C(n-1, n-1+i) % p) * ((m-1, m-1+k-2*i) % p);
    // }    

    // cout << sum;

    for(int i = 1; i <= n; ++i)
        a[i] = 1;

    
    for(int i = n+1; i <= m; ++i)
        a[i] = 2;    

    n += m;
    for(int i = 1; i <= n; ++i)
    {
        for(long long int j = 0; j <= k; ++j)
        {

            dp[i][0] = 1;
            dp[1][j] = 1;
            if(j < 0)
                dp[i][j] = 0;
            dp[i][j] = (dp[i-1][j] % p + dp[i][j-a[i]] % p) % p;
        }
    }

    cout << dp[n][k] % p;   


    return 0;
}