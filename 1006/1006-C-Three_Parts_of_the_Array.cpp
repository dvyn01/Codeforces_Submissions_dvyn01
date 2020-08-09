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
    ll a[n];
    f(0, n) cin>>a[i];
    vll b(n,0), c(n,0);
    b[0] = a[0]; c[0] = a[n-1];
    f(1, n) b[i] = b[i-1] + a[i];
    f(1, n) c[i] = c[i-1] + a[n-i-1];
    ll s=0;
    f(0, n)
    {
        ll p = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
        if(c[p] == b[i])
        {
            if(p+i < n-1)
                s = max(s, b[i]);
        }
    }
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
