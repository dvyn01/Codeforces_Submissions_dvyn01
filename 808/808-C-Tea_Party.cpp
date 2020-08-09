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

    ll n, w;
    cin>>n>>w;
    pll p;
    ll a[n], b[n]={0};
    f(0, n) {   cin>>a[i];      p.pb(mp(a[i], i)); }
    f(0, n)
    {
        ll k;
        if(a[i]%2)
            k = a[i]/2+1;
        else k = a[i]/2;
        w -= k;
        b[i] = k;
    }
    if(w<0){cout<<-1; return 0;}
    sort(p.begin(), p.end());
    ll x=n-1;
    while(w>0)
    {
        ll k = min(a[p[x].second]-b[p[x].second], w);
        b[p[x--].second] += k;
        w -= k;
    }
    f(0, n) cout<<b[i]<<" ";


     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

