#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("COVER.inp", "r", stdin);
    freopen("COVER.out", "w", stdout);

    int n, a, b;
    pair<int, int> l[100008];
    
    cin >> n >> a >> b;

    for(int i = 0; i < n; i++)
    {
        cin >> l[i].first >> l[i].second;
        if(l[i].first <= a && l[i].second >= b)
        {
            cout << 1 << "\n";
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;
    
    return 0;
}