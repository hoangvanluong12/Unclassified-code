#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("FBALLKIT.inp", "r", stdin);
    freopen("FBALLKIT.out", "w", stdout);

    int n;

    pair<int, int> a[100008], res[100008];
    int cnt[100008] = {0};

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second; 
        res[i].first = n - 1;
        cnt[a[i].first]++;
    }

    for(int i = 0; i < n; i++)
    {
        if(!cnt[a[i].second])
            res[i].second += n - 1;
        else
        {
            res[i].first += cnt[a[i].second];
            res[i].second += 2 * (n - 1) - res[i].first;
        }
        cout << res[i].first << " " << res[i].second << "\n";
    }
    
    return 0;
}