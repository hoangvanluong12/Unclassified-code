#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, h[100000];
    stack<int> s;

    freopen("MAXRECT.inp", "r", stdin);
    freopen("MAXRECT.out", "w", stdout);

    cin >> n; 
    
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    int maxArea = 0, t, area;

    int i = 0;

    while(i < n)
    {
        if(s.empty() || h[s.top()] <= h[i])
        {
            s.push(i);
            ++i;
        }
        else    
        {   
            t = s.top();
            s.pop();
            if(s.empty())
            {
                area = h[t] * i;
            }
            else
                area = h[t] * (i - s.top() - 1);
            
            maxArea = max(maxArea, area);
            
         }
    }
    
    while(!s.empty())
    {
        t = s.top();
        s.pop();
        if(s.empty())
        {
            area = h[t] * i;
        }
        else
            area = h[t] * (i - s.top() - 1);

        maxArea = max(maxArea, area);
    }

    cout << maxArea;

    return 0;
}