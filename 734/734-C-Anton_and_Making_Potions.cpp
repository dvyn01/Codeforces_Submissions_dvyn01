//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll,ll>>

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, m, k, x, s;
    cin>>n>>m>>k>>x>>s;
    ll a[1000000], b[1000000], c[1000000], d[1000000];
    f(0,m) cin>>a[i];
    f(0,m) cin>>b[i];
    f(0,k) cin>>c[i];
    f(0,k) cin>>d[i];
	ll t =(n-c[upper_bound(d,d+k,s)-d-1])*x;
	f(0,m)
		{
		    if(b[i]<=s)
            t = min(t ,(n-c[upper_bound(d,d+k,s-b[i])-d-1])*a[i]);
		}
    cout<<t;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
