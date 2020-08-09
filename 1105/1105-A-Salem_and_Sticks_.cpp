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
#define f(a,b) for(ll i = a; i < b; i++)
#define fr(a,b) for(ll j = a; j >= b; j--)
#define fi(a,b) for(ll j = a; j < b; j++)
#define fii(a,b) for(ll k = a; k < b; k++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector< pair<ll,ll> >
#define ld long double
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
       freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n;
	cin>>n;
	ll a[n];
	f(0, n)		cin>>a[i];
	ll mc = 1e18, t = -1;
	f(1, 101)
	{
		ll c = 0;
		fi(0, n)
		{
			c += min(abs(a[j] - i), min(abs(a[j] - i + 1), abs(a[j] - i - 1)));
		}
		if(c < mc)
		{
			mc = c;
			t = i;
		}
	}
	cout<<t<<" "<<mc;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
