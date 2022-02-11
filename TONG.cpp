#include <bits/stdc++.h>

using namespace std;

const long long int mod = 1e9 + 7;
int a[1000012];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("TONG.inp", "r", stdin);
    freopen("TONG.out", "w", stdout);

    int n, j = 0;
    long long p, k, k1, k2, sum = 0;

    cin >> n >> k >> p;

    
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    p = (!(p % n)) ? n : p % n;

    k1 = k % n;
    k2 = k / n;

    long long res = sum * k2;

    for(int i = p; j < k1; i++, j++)
    {
        if(i % n == 0)
            res += a[n];
        else
            res += a[i%n];
        res %= mod;
        // cout << a[i%n] << " ";
    }

    cout << res;

    return 0;
}