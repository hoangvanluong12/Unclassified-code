// #include <bits/stdc++.h>

// using namespace std;

// bool prime[1000008];

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("SDB.inp", "r", stdin);
//     freopen("SDB.out", "w", stdout);

//     memset(prime, true, sizeof(prime));

//     for(int i = 2; i * i <= 1000000; ++i)
//     {
//         if(prime[i] == true)
//             for(int j = i * i; j <= 1000000; j += i)
//                 prime[j] = false;
//     }    

//     // prime[3] = false;


//     int t;
//     cin >> t;

//     while(t--)
//     {    
//         int a, b;
//         cin >> a >> b;
//         int c = 0;
//         for(int i = 2; i <= 500; ++i)
//         {
//             if(prime[i])
//             {
//                 long long int tmp = pow(3 * i, 2);
//                 if(tmp > b)
//                     break;

//                 // cout << tmp << " "; 

//                 if(tmp >= a)
//                     c += 1;
//             }
//         }
//         cout << c << "\n";
//     }

//     return 0;
// }

// above approach: check if i is a prime number then (3 * i)^2 is a special number 

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
int divs_of[MAX + 8], cnt[MAX + 8];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("SDB.inp", "r", stdin);
    freopen("SDB.out", "w", stdout);

    divs_of[1] = 1;

    for(int i = 2; i <= MAX; ++i)
    {
        divs_of[i] += 1;
        for(int j = i; j <= MAX; j += i)
            divs_of[j]++;
    }

    // for(int i = 1; i <= 100; i++)
    //     cout << divs_of[i] << " ";

    for(int i = 1; i <= MAX; ++i)
    {
        cnt[i] = cnt[i - 1];
        if(!(i % 3) and divs_of[i] == 9)
            cnt[i]++;
    }

    
    // for(int i = 1; i <= 100; i++)
    //     cout << cnt[i] << " ";

    int t;
    cin >> t;

    while(t--)
    {
        int a, b;
        cin >> a >> b;    
        cout << cnt[b] - cnt[a] << "\n";
    }

    return 0;
}