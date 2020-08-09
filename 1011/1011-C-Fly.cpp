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

    ll n;
    ld m;
    cin>>n>>m;
    ld a[n], b[n];
    f(0, n) cin>>a[i];
    f(0, n) cin>>b[i];
    ld l=1, r=1000000000, ans=1e18;
    ld y = 1e9;
    bool okk = true;
    f(0, n)
    {
        ld aa = (m+y)/a[i];
        y -= aa;
        aa = (m+y)/b[i];
        y -= aa;
        if(y<=0 && i!=n-1)
        {okk=false; break; }
        if(y<0 && i==n-1)
        {okk=false; break; }
    }
    if(okk)
        ans = 1e9;
    while(l <= r)
    {
        ld mid = (l+r)/2;
        ld s=0, x=mid;
        bool ok = true;
        f(0, n)
        {
            ld aa = (m+x)/a[i];
            x -= aa;
            aa = (m+x)/b[i];
            x -= aa;
            if(x<=0 && i!=n-1)
            {ok=false; break; }
            if(x<0 && i==n-1)
            {ok=false; break; }
        }
        if(!ok)
            l = mid+0.00000002;
        else{
            ans = min(ans, mid);
            r = mid-0.00000002;
        }
    }
    if(ans!=1e18)
        cout<<fixed<<setprecision(20)<<ans;
    else cout<<-1;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

