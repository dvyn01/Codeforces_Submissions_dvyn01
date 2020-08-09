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
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k, l;
    cin>>n>>m>>k>>l;
    ll x = n / m;
    if(x == 0)
    {
        cout<<-1;
        return 0;
    }
    l += k;
    if(l > n)
    {
        cout<<-1;
        return 0;
    }
    if(x * m < l)
    {
        cout<<-1;
        return 0;
    }
    ll ans;
    if(l <= m)
        ans = 1;
    else if(l % m == 0)
        ans = l / m;
    else ans = l / m + 1;
    if(ans > x)
        ans = -1;
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
