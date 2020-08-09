//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
ll w[10000], h[10000], n, ans[100000], dp[100000];

ll rec(ll k)
{
    if(dp[k])
        return dp[k];
    ll m=0;
    f(1,n+1)
    {
        if(w[i]>w[k]  && h[i]>h[k])
        {
            ll p = rec(i);
            if(p > m)
            {
                ans[k]=i;
                m = p;
            }
        }
    }
    return dp[k]=m+1;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll ww, hh;
    cin>>n>>w[0]>>h[0];
    f(1, n+1)
        cin>>w[i]>>h[i];
    ll k=0;
    ll r = rec(k);
    cout<<r-1<<"\n";
    if(r-1==0) return 0;
    for(ll i=0; ; )
    {
        cout<<ans[i]<<" ";
        i = ans[i];
        if(ans[i]==0)
            break;
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

