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

    ll n, t;
    cin>>n>>t;
    ll a[n];
    ll s = 0, mn = 1e18, c=0;
    f(0, n)
    {
        cin>>a[i];
        if(t >= a[i] + s)
            s += a[i],  c++;
        if(a[i] < mn)
            mn = a[i];
    }
    ll ans = 0;
    if(s == 0)
    {
        cout<<0;
        return 0;
    }
    ans += t / s * c;
    t -= t / s * s;
    while(t >= mn)
    {
        c = 0;
        ll s1 = 0;
        f(0, n)
        {
            if(t >= a[i]+s1)
                s1 += a[i], c++;
        }
        if(s1 == 0)
            break;
        ans += t / s1 * c;
        t -= t / s1 * s1;
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

