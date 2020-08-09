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
ll a[100005], n, c[1000050];

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    ll ans = 0;
    c[0] = 1;
    f(1, n+1)
    {
        cin>>a[i];
        vll v;
		for(int j=1;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				v.push_back(j);
				if(j != a[i]/j)
					v.push_back(a[i]/j);
			}
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for(auto &it:v)
		{
			c[it]+=c[it-1];
			c[it] %= mod;
		}
    }
    f(1, n+1)
        ans = (ans + c[i]) % mod;
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
