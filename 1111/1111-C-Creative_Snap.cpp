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
ll x, n, k, a, b, ans;
map<ll, ll> m, m1;
vll v;

ll rec(ll s, ll e)
{
    ll mid = s + e >> 1;
    if(s == e)
    {
        return b*m1[s];
    }
    auto it1 = lower_bound(v.begin(), v.end(), s);
    auto it2 = upper_bound(v.begin(), v.end(), mid);
    auto it3 = upper_bound(v.begin(), v.end(), e);
    it1--;
    it2--;
    it3--;
    ll k1 = m[*it2] - m[*it1],  k2 = m[*it3] - m[*it2];
    ll x = (e-s+1) * (k1 + k2) * b;
    if(k1 != 0 && k2 != 0)
        x = min(x, rec(s, mid) + rec(mid+1, e));
    if(k1 == 0)
        x = min(x, a + rec(mid+1, e));
    else if(k2 == 0)
        x = min(x, a + rec(s, mid));
  //  cout<<it1 -> first<<" -- 1 --  "<<it1 -> second<<"\n";
  //  cout<<it2 -> first<<" -- 2 -- "<<it2 -> second<<"\n";
  //  cout<<it3 -> first<<" -- 3 -- "<<it3 -> second<<"\n";
  //  cout<<s<<" "<<e<<" "<<k1<<" "<<k2<<" -->  "<<x<<"\n";
    return x;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k>>a>>b;
    f(0, k)     {   cin>>x;     if(!m[x])   v.pb(x); m[x]+=1; m1[x]+=1;   }
    v.pb(0);
    sort(v.begin(), v.end());
    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(it != m.begin())
        {
            auto it1 = --it;
            ++it;
            it -> second += it1 -> second;
        }
    }
    ll ans = rec(1, (1LL << n));
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

