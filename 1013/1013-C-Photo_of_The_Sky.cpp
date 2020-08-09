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
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    ll a[2*n];
    f(0, 2*n)   cin>>a[i];
    sort(a, a+2*n);
    ll mn1=a[0], mx1=a[n-1], mn2=a[n], mx2=a[2*n-1];
    ll ans = (mx2-mn2)*(mx1-mn1);
    ll x = a[n-1]-a[0], in=0;
    f(1, n)
    {
        if(a[i+n-1]-a[i] < x)
        {
            x = a[i+n-1]-a[i];
            in = i;
        }
    }
    mn1=1e18, mx1=0, mn2=1e18, mx2=0;
    f(in, in+n)
    {
        mn1 = min(mn1, a[i]);
        mx1 = max(mx1, a[i]);
    }
    f(0, 2*n)
    {
        if(i>=in && i<in+n)
            continue;
        mn2 = min(mn2, a[i]);
        mx2 = max(mx2, a[i]);
    }
    ans = min(ans, (mx2-mn2)*(mx1-mn1));
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
