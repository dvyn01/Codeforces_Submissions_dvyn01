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

vll vv[1050][1050];

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
    map<ll, map<ll, ll>> mm;
    cin>>n;
    pll p;
    f(0, n)
    {
        ll x, y;
        cin>>x>>y;
        p.pb(mp(y, x));
        vv[x][y].pb(i+1);
    }
    ll k;
    cin>>k;
    map<ll, ll> m;
    vll v[1050];
    f(0, k)
    {
        ll x;
        cin>>x;
        m[x]++;
        v[x].pb(i+1);
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    pll ans;
    ll s = 0;
    f(0, n)
    {
        auto it = m.lower_bound(p[i].second);
        if(it != m.end())
        {
          //  cout<<vv[p[i].second][p[i].first].size()<<" ";
            s += p[i].first;
            ll kk = it -> first;
            ans.pb(mp(*--vv[p[i].second][p[i].first].end(), (*--v[it -> first].end())));
            it -> second--;
            if(it -> second == 0)
                m.erase(it);
            v[kk].erase(v[kk].begin() + v[kk].size() - 1);
            vv[p[i].second][p[i].first].erase(vv[p[i].second][p[i].first].begin() + vv[p[i].second][p[i].first].size() - 1);
           // cout<<vv[p[i].second][p[i].first].size()<<"\n";
        }
    }
    cout<<ans.size()<<" "<<s<<"\n";
    f(0, ans.size())
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

