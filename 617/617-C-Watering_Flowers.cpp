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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, x1, y1, x2, y2;
    cin>>n>>x1>>y1>>x2>>y2;
    ll ans = 1e18;
    vll u, v;
    f(0, n)
    {
        ll a, b;
        cin>>a>>b;
        ll p = ((x1-a)*(x1-a)) + ((y1-b)*(y1-b));
        u.pb(p);
        ll q = ((x2-a)*(x2-a)) + ((y2-b)*(y2-b));
        v.pb(q);
    }
    v.pb(0); u.pb(0);
    f(0, n+1)
    {
        ll p = u[i];
        ll f=0;
        fi(0, n+1)
        {
            if(u[j] > p)
                f = max(f, v[j]);
        }
        ans = min(ans, p+f);
    }
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

