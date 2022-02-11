#include <bits/stdc++.h>

using namespace std;

bool check(long long n, int k)
{
    int c = 0;
    int n2;
    while(n != 0)
    {
        n2 = n % 10;
        if(n2 == 5)
            c++;
        n /= 10;
    }
    return (c == k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("MIN.inp", "r", stdin);
    freopen("MIN.out", "w", stdout);

    long long n;
    int k;  

    cin >> n >> k;
    

    // if(check(n, k))
    //     cout << 1;
    // else
    //     cout << 0;

    // for(int i = 0; i < k; i++)
    //     cout << 5;


    
    long long n2 = n;
    while(!check(n, k) || n <= n2)
    {
        n++;
    }
    cout << n;

    return 0;
}


 