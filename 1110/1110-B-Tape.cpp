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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin>>n>>m>>k;
    ll a[n];
    f(0, n)     cin>>a[i];
    ll b[n];
    pll p;
    f(0, n-1)   {   b[i] = a[i+1] - a[i];       p.pb(mp(b[i], i));  }
    sort(p.begin(), p.end());
    ll c = n-k, cp = 0, y;
    bool bb[n+1];        memset(bb, false, sizeof(bb));
    while(c--)
        y = p[cp++].second, bb[y] = true;
    ll s = 0, ans = 0, cl = 0, cr = 0;
    f(0, n)
    {
        if(i != 0 && bb[i-1])
            cr = a[i];
        else {  if(i != 0) ans += cr - cl + 1; cl = a[i]; cr = a[i];   }
    }
    ans += cr - cl + 1;
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

