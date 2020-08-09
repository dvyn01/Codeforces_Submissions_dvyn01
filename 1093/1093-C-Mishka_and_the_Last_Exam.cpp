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

    ll n;
    cin>>n;
    ll a[n/2];
    f(0, n/2)       cin>>a[i];
    ll ans[n];
    memset(ans, 0, sizeof(ans));
    ll fp = 0, lp = n-1;
    f(0, n/2)
    {
        if(i == 0)
        {
            ans[fp++] = 0;
            ans[lp--] = a[0];
            continue;
        }
        if(a[i] > a[i-1])
        {
            ll k = a[i] - a[i-1];
            ans[fp++] = ans[fp - 2];
            ans[lp--] = ans[lp + 2];
            ans[fp - 1] += k;
        }
        else if(a[i] < a[i-1])
        {
            ll k = a[i] - a[i-1];
            ans[fp++] = ans[fp - 2];
            ans[lp--] = ans[lp + 2];
            ans[lp + 1] += k;
        }
        else
        {
            ans[fp++] = ans[fp - 2];
            ans[lp--] = ans[lp + 2];
        }
    }
    f(0, n)     cout<<ans[i]<<" ";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

