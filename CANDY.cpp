#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int n, k;

    // freopen("CANDY.inp", "r", stdin);
    // freopen("CANDY.out", "w", stdout);

    cin >> n >> k;

    long long int res = 0;

	switch(k)
    {
        case 1:
            res = 1;
            break;
        case 2:
            res = (n - 1) / 2;
            break;
        case 3:
            for(int i = 1; i < n / 3; i++)
                res += (n - i - 1) / 2 - i;
            break;
        case 4:
            for(int i = 1; i < n / 4; i++)
            {
                for(int j = i + 1; j < (n - i) / 3; j++)
                {
                    res += (n - j - i - 1) / 2 - j;
                }
            }
            break;
    }
	
	cout << res;
    return 0;
} 