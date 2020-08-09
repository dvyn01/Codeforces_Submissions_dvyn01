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
    ll a[n+1],    b[n+1];
    f(1, n+1)     cin>>a[i]>>b[i];
    ll ans[n + 1];
    if(n == 3)
    {
        cout<<"1 2 3";
        return 0;
    }
    ans[1] = 1;
    ll cp = 1;
    while(cp < n)
    {
        ll k1 = a[ans[cp]],  k2 = b[ans[cp]];
        ll k3 = a[k1],  k4 = b[k1], k5 = a[k2], k6 = b[k2];
        if(k3 == k2 || k4 == k2)
            ans[++cp] = k1;
        else ans[++cp] = k2;
    }
    f(1, n+1) cout<<ans[i]<<" ";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

