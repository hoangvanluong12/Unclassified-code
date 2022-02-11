#include <bits/stdc++.h>

using namespace std;


int n, k;
long int a[1000000];
int main()
{
 
    freopen("MINIMUM.inp", "r", stdin);
    freopen("MINIMUM.out", "w", stdout);

    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    

    for(int i = 0; i < n - k + 1; ++i)
    {
        long int* m = min_element(a + i, a + i + k);
        cout << *m << " ";
    }


    return 0;
}