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

    ll n, m, s=0;
    cin>>n>>m;
    vll v;
    ll a[n], b[n];
    f(0, n) {   cin>>a[i]>>b[i];    v.pb(a[i]-b[i]); s+=a[i];}
    sort(v.begin(), v.end());
    ll k = n-1, ans=0;
    bool ok = true;
    while(s>m)
    {
        if(k<0){ok=false; break;}
        s -= v[k];
        k--;
        ans++;
    }
    if(!ok) cout<<-1;
    else cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

