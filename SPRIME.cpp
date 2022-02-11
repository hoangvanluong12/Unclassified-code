#include <bits/stdc++.h>

using namespace std;

const int maxN = 3e6 + 8;
bool prime[maxN];
int f[maxN];

int sum_digits(int x)
{ 
    int sum = 0; 
    while(x)
    {
        sum += x % 10; 
        x /= 10;
    }
    return sum;
}

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("SPRIME.inp", "r", stdin);
    freopen("SPRIME.out", "w", stdout);


    memset(prime, 0, sizeof(prime));

    f[1] = 0; 

    for (int i = 2; i < maxN; i++) 
    { 
        f[i] = f[i - 1]; 
        if (!prime[i]) 
        { 
            f[i] += (sum_digits(i) % 5 == 0); 
            for (int j = i + i; j < maxN; j += i) 
                prime[j] = 1; 
        } 
    }

    int t, l, r; 
    cin >> t; 
    while (t--) 
    { 
        cin >> l >> r; 
        cout << f[r] - f[l - 1] << "\n"; 
    } 
    
    return 0;
}