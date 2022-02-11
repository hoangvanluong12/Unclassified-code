#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> i1, pair<int, int> i2)
{
    if(i1.first == i2.first)
        return (i1.second < i2.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("TENNIS.inp", "r", stdin);
    freopen("TENNIS.out", "w", stdout);

    int c[100008];
    int n, a[100008], b[100008];
    pair<int, int> res[100008];
    
    cin >> n;

    int x, len_a = 0, len_b = 0;
    a[0] = b[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        c[i] = x;
        if(x == 1)
        {
            a[i] = a[i - 1] + 1;
            b[i] = b[i - 1];
        }
        else
        {
            b[i] = b[i - 1] + 1;
            a[i] = a[i - 1];
        }
    }

    // for(int i = 1; i <= n; i++)
    //     cout << a[i] << " ";
    // cout << "\n";
    // for(int i = 1; i <= n; i++)
    //     cout << b[i] << " ";
    // cout << "\n";

    int s1, s2, last1, last2, q, w, mn, ct = 0, qwe = 0;

    for(int t = 1; t <= n; t++)
    {
        s1 = s2 = last1 = last2 = 0;
        
        while(true)
        {
            q = lower_bound(a + 1, a + n + 1, last1 + t) - a;
            w = lower_bound(b + 1, b + n + 1, last2 + t) - b;
            
            if(q > n and w > n)
                break;
            mn = q;
            if(mn > w)
            {
                mn = w;
                s2++;
            }
            else s1++;
            if(mn == n)
            {
                if( (s1 > s2 and c[n] == 1) or (s2 > s1 and c[n] == 2) )
                {
                    ct++;
                    res[qwe].first = max(s1, s2);
                    res[qwe++].second = t;
                }
                break;
            }
            last1 = a[mn];
            last2 = b[mn];
        }   
    }
    
    sort(res, res + qwe, compare);

    cout << qwe << "\n";

    for(int i = 0; i < qwe; i++)
        cout << res[i].first << " " << res[i].second << "\n";

    return 0;
}