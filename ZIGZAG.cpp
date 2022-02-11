#include <bits/stdc++.h>

using namespace std;

int a[1000008], b[1000008];
long long f1[1000008], f2[1000008];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("ZIGZAG.inp", "r", stdin);
    freopen("ZIGZAG.out", "w", stdout);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];        

    long long int res = max(a[0], b[0]);
    f1[0] = a[0];
    f2[0] = b[0];

    for(int i = 1; i < n; i++)
    {
        f1[i] = max(f1[i - 1], f2[i - 1] + a[i]);
        f2[i] = max(f2[i - 1], f1[i - 1] + b[i]);
        res = max(f1[i], f2[i]);
    }

    cout << res;

    return 0;
}