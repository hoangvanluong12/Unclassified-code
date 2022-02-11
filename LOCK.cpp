#include <bits/stdc++.h>    

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("LOCK.inp", "r", stdin);
    freopen("LOCK.out", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    string res = s;
    s += s;
    string sub; 

    for(int i = 0; i <= n; i++)
    {
        sub = s.substr(i, n);

        while(sub[0] != '0')
        {
            for(int i = 0; i < n; i++)
            {
                if(sub[i] == '9')
                    sub[i] = '0';
                else 
                    sub[i] += 1;
            }
        }
        // cout << sub << "\n";
        res = min(res, sub);
    }

    cout << res;
    return 0;
}