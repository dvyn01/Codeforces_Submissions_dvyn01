/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *No Need*
	  #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin>>n>>m;
    ll ans[n+m];        memset(ans, 0, sizeof(ans));
    vll v;
    ll a[n+m],      b[n+m];
    f(0, m+n)     cin>>a[i];
    f(0, m+n)     {   cin>>b[i];      if(b[i] == 1)       v.pb(a[i]); }
    f(0, m+n)
    {
        if(b[i] == 0)
        {
            ll k1 = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            ll k2 = k1 - 1;
            if(k1 == v.size())
            {
                ans[k2]++;
                continue;
            }
            if(k1 == 0)
            {
                ans[k1]++;
                continue;
            }
            if(abs(v[k2] - a[i]) <= abs(v[k1] - a[i]))
                ans[k2]++;
            else ans[k1]++;
        }
    }
    f(0, v.size())
        cout<<ans[i]<<" ";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

