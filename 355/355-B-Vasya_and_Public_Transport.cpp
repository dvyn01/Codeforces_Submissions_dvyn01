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
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    ll n, m;
    cin>>n>>m;
    ll p[n], q[m];
    f(0, n) cin>>p[i];
    f(0, m) cin>>q[i];
    ll s1=0, s2=0;
    f(0, n) s1 += min(b, a*p[i]);
    f(0, m) s2 += min(b, a*q[i]);
    s1 = min(s1, c);
    s2 = min(s2, c);
    ll ans = min(s1+s2, d);
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

