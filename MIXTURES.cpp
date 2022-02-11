#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("MIXTURES.inp", "r", stdin);
    // freopen("MIXTURES.out", "w", stdout);
    
    
    int t;
    cin >> t;

    while(t--)
    {
        int n, a[102], f[102][102], s[102] = {0};
        cin >> n;

        for(int i = 1; i <= n; i++)
            cin >> a[i];

        for(int i = 0; i <= n; i++)
            f[i][i] = 0;

        for(int i = 1; i <= n; i++)
            s[i] = s[i - 1] + a[i];
        

        // for(int i = 1; i <= n; i++)
        // {
        //     cout << s[i] << " ";
        // }
        
        for(int k = 1; k <= n - 1; k++)
        {
            for(int i = 1; i <= n - k; i++)
            {
                int j = i + k;
                f[i][j] = oo;
                for(int u = 1; u <= j; u++)
                    f[i][j] = min(f[i][j], f[i][u] + f[u+1][j] + ((s[u] - s[i - 1]) % 100) * ((s[j] - s[u]) % 100));
            }
        }        


        cout << f[1][n] << "\n";    

    }

    return 0;
}