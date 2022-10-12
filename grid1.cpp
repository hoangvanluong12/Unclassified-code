#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mn=1001;
int n,m,res=-1e18;
int dp[mn][mn];
char ch,a[mn][mn];
void nhapfile()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);     cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)cin>>ch,a[i][j]=ch;
}
void dyp()
{
    for(int j=1;j<=n;j++)
        if(a[1][j]=='.')dp[1][j]=1;else break;
    for(int i=1;i<=m;i++)
        if(a[i][1]=='.')dp[i][1]=1;else break;
    for(int i=2;i<=m;i++)
        for(int j=2;j<=n;j++)
            if(a[i][j]=='#')dp[i][j]=0;
            else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
    cout<<dp[m][n];
}
signed main()
{
    nhapfile();
    dyp();
    return 0;
}
