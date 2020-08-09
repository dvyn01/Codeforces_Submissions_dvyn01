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

ll msb(ll n)
{
    ll k = 31;
    while(!((1LL << k) & n))
        k--;
    return k;
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

    ll n, q;
    cin>>n>>q;
    ll a[31];
    memset(a, 0, sizeof(a));
    f(0, n)
    {
        ll x;
        cin>>x;
        a[msb(x)]++;
    }
    while(q--)
    {
        ll x;
        cin>>x;
        ll ans = 0;
        fr(30, 0)
        {
            ll k = min(x / (1LL << j), a[j]);
            x -= k * (1LL << j);
            ans += k;
        }
        if(x)
            cout<<"-1\n";
        else cout<<ans<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

