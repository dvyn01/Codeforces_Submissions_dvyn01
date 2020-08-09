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
  //     freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, kk;
   	cin>>n>>kk;
   	string s;
   	cin>>s;
   	ll a[n+1];	memset(a, 0, sizeof(a));
  // 	ll b[n+1];	memset(b, -1, sizeof(b));
   	f(0, n)
   	{
   		if(i != n-1 && s[i] == s[i+1])
   		{
   			ll j = i;
   			while(j < n-1 && s[j] == s[j+1])
   				j++;
   			ll c = j-i+1;
   			fii(i, j+1)	{	a[k] = c--;	}
   			i = j;
   		}
   		else a[i] = 1;
   	}
   	ll ans = 0;
  // 	f(0, n)		cout<<a[i]<<"\n";
   	fii(0, 26){
   		char xxx = 'a' + k;
   		ll x = 0;
   		f(0, n)
   		{
   		    if(s[i] == xxx && a[i] >= kk)
   			{
   				x++;
   				i += kk-1;
   			}
   		}
   		ans = max(ans, x);
   	}
   	cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

