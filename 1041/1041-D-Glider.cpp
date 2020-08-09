/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
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

    ll n, h, s=0;
    cin>>n>>h;
    pll p;
    ll xxx = 0;
    f(0, n)
    {
        ll l, r;
        cin>>l>>r;
        s += r - l;
        p.pb(mp(l, r));
    }
    if(p[n-1].second - p[0].first - s < h)
    {
        cout<<s+h;
        return 0;
    }
    vll a;
    a.pb(0);
    f(1, n)
    {
        a.pb(a[i-1] + p[i].first - p[i-1].second);
    }
    ll ans = 0;
    f(0, n)
    {
     //   cout<<i<<" "<<ans<<"\n";
        ll x = a[i] + h;
        ll k = lower_bound(a.begin(), a.end(), x) - a.begin();
        if(k == n)
        {
            ll pp = a[n-1] - a[i];
            ll dd = p[n-1].second - p[i].first;
            dd += h - pp;
            if(dd > ans)
                ans = dd;
            continue;
        }
        if(a[k] - a[i] == h)
        {
            if(p[k].first - p[i].first > ans)
                ans = p[k].first - p[i].first;
        }
        else
        {
            k--;
            ll pp = p[k].second - p[i].first;
            ll dd = a[k] - a[i];
            if(pp + h - dd > ans)
                ans = pp + h - dd;
        }
    }
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
