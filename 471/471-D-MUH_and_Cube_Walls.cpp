/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 2038074743
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
#define mod1 1000000007

ll powmod(ll x, ll y)
{
    x = x % mod;
    ll r = 1;
    while(y > 0)
    {
        if(y & 1)
            r = (r * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return r;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, m;
    cin>>n>>m;
    ll a[n], b[m];
    f(0, n) cin>>a[i];
    f(0, m) cin>>b[i];
    if(m == 1)
    {
        cout<<n;
        return 0;
    }
    f(0, n-1)   {   a[i] = a[i+1] - a[i];   a[i] += 1000000007; }
    f(0, m-1)   {   b[i] = b[i+1] - b[i];   b[i] += 1000000007; }
    ll ans=0;
    ll mmi = powmod(mod1, mod-2);
    ll s1 = 0, s2 = 0;
    f(0, m-1)
    {
        ll k = powmod(mod1, i);
        s1 = (s1 + (a[i] * k) % mod ) % mod;
        s2 = (s2 + (b[i] * k) % mod) % mod;
    //    cout<<s1<<" "<<s2<<"\n";
    }
    if(s1 == s2)    ans++;
    ll ci=0;
    ll xx = powmod(mod1, m-2);
    f(m-1, n-1)
    {
        s1 = (s1 - a[ci++] + mod) % mod;
        s1 = (s1 * mmi) % mod;
        s1 = (s1 + (a[i] * xx) % mod ) % mod;
        if(s1 == s2)    ans++;
   //     cout<<s1<<" ";
    }
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

