/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, m, mx=0, ss=0;
    cin>>n>>m;
    ll a[n];
    f(0, n) {   cin>>a[i];  ss+=a[i];  if(a[i] > mx) mx = a[i]; }
    sort(a, a+n);
    ll s = n * mx;
    if(s >= m+ss)
    {
        cout<<mx<<" "<<mx+m;
        return 0;
    }
    ll k = ss + m - s;
    ll p;
    if(k%n) p = k/n+1;  else p = k/n;
    cout<<mx+p<<" "<<mx+m;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

