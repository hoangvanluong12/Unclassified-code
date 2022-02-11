#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    freopen("PERM.inp", "r", stdin);
    freopen("PERM.out", "w", stdout);

    string n, m;

    cin >> n >> m;

    string res;
    if(n.size() > m.size())
    {
        cout << -1;
    }
    else if(n.size() < m.size())
    {
        while(next_permutation(n.begin(), n.end()))
        {
            res = n;
        }
        cout << res;
    }
    else if(n.size() == m.size())
    {   
        sort(n.begin(), n.end());
        res = n;
        while(next_permutation(n.begin(), n.end()))
        {
            res = (n < m && n >= res) ? n : res;
        }
        cout << res;
    }

    return 0;
}   