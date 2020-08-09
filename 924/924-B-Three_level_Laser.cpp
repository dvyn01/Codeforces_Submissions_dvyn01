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

    ll n, u;
    cin>>n>>u;
    vector<ld> v;
    f(0, n){ld x;   cin>>x;     v.pb(x); }
    ld ans=0.0;
    bool ok = false;
    f(0, n-2)
    {
        ll x = upper_bound(v.begin(), v.end(), v[i]+u) - v.begin();
        x--;
        if(x-i < 2)
            continue;
        ok = true;
        ld p = v[x] - v[i], q = v[x] - v[i+1];
        if(q/p > ans)
            ans = q/p;
    }
    if(ok)  cout<<fixed<<setprecision(15)<<ans;
    else cout<<"-1";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

