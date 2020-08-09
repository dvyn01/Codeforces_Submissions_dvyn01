/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
      #include <ext/pb_ds/tree_policy.hpp>

      using namespace __gnu_pbds;       */
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
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin>>n>>m;
    ll a[n];
    f(0, n)     cin>>a[i];
    ll c[n];
    f(0, n)     cin>>c[i];
    pll p;
    f(0, n)     p.pb({c[i], i});
    sort(p.begin(), p.end());
    ll cp = 0;
    bool ok = true;
    while(m--)
    {
        ll t, d, ans = 0;
        cin>>t>>d;
        t--;
        if(!ok)
        {
            cout<<"0\n";
            continue;
        }
        if(a[t] >= d)
        {
            ans = d * c[t];
            cout<<ans<<"\n";
            a[t] -= d;
            continue;
        }
        ans += a[t] * c[t];
        d -= a[t];
        a[t] = 0;
        while(d)
        {
            if(cp == p.size())
            {
                cout<<"0\n";
                ok = false;
                break;
            }
            ll x = a[p[cp].second];
            if(x == 0)
            {
                cp++;
                continue;
            }
            ll xx = min(x, d);
            ans += c[p[cp].second] * xx;
            d -= xx;
            a[p[cp].second] -= xx;
            if(a[p[cp].second] == 0)
                cp++;
        }
      //  f(0, n)     cout<<a[i]<<" ";    cout<<cp<<"\n";
        if(!ok)
            continue;
        cout<<ans<<"\n";
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
