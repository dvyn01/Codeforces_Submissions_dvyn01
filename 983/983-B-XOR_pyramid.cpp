/*
          * AUTHOR : Divyanshu *
*/

// MORE SHORTER .. !!

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define fi(a,b) for(ll j=a; j<b; j++)
ll dp[5005][5005], ans[5005][5005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, l, r, q;
    cin>>n;
    ll a[n+1];
    f(1, n+1)          cin>>a[i],  dp[i][i] = a[i],    dp[i-1][i] = a[i-1] ^ a[i],     ans[i][i] = a[i];
    f(3, n+1)   fi(1, n-i+2)    dp[j][j+i-1] = dp[j][j+i-2] ^ dp[j+1][j+i-1];
    f(2, n+1)   fi(1, n-i+2)    ans[j][j+i-1] = max(dp[j][j+i-1], max(ans[j][j+i-2], ans[j+1][j+i-1]));
    cin>>q;
    while(q--)
        cin>>l>>r,      cout<<ans[l][r]<<"\n";
    return 0;
}

