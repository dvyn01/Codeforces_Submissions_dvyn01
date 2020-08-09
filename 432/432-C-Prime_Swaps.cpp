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
bool b[100050];
vll p;

void sieve()
{
    f(2, 100050)
    {
        if(!b[i])
        {
            p.pb(i);
            fi(2*i, 100050)
            {
                b[j] = true;
                j += i-1;
            }
        }
    }
}



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
    sieve();
    map<ll, ll> m;
    ll a[n+1];
    vll v;
    f(1, n+1){cin>>a[i];   m[a[i]] = i;     v.pb(a[i]);}
    sort(v.begin(), v.end());
    f(1, n+1)
       a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    f(1, n+1)   m[a[i]] = i;
    pll ans;
    for(auto it = m.begin(); it != m.end(); it++)
    {
        while(it -> first != it -> second)
        {
            ll k = it -> second - it -> first;
            ll x = upper_bound(p.begin(), p.end(), k+1) - p.begin();
            x--;
            x = p[x];
            x--;
            ll y = it -> second - x;
            m[a[y]] = it -> second;
            swap(a[it->second], a[y]);
            ans.pb(mp(it -> second, y));
            it -> second = y;
        }
    }
    cout<<ans.size()<<"\n";
    f(0, ans.size())    cout<<min(ans[i].first, ans[i].second)<<" "<<max(ans[i].first, ans[i].second)<<"\n";


     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

