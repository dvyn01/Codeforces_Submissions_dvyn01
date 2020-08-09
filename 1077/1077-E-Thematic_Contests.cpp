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
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    map<ll, ll> m;
    cin>>n;
    f(0, n)     cin>>x,     m[x]++;
    vll v;
    for(auto it = m.begin(); it != m.end(); it++)
        v.pb(it -> second);
    sort(v.begin(), v.end());
    ll cse = 1,      ans = 0;
    while(lower_bound(v.begin(), v.end(), cse) != v.end())
    {
        ll cp = -1, cs = 0, ce = cse;
        while(1)
        {
            ll k = lower_bound(v.begin() + cp + 1, v.end(), ce) - v.begin();
            if(k == v.size())
                break;
            cs += ce;
            ce *= 2;
            cp = k;
        }
        if(cs > ans)
            ans = cs;
        cse++;
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

