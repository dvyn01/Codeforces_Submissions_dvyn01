//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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

    ll n, m, k;
    cin>>n>>m>>k;
    ll x = k-1, y = n-k;
    ll ans=0;
    ll l=0, r=m-n;
    while(l <= r)
    {
        ll mid = (l+r)/2;
        ll s=0;
        s += mid;
        if(mid-1 <= x)
            s += mid*(mid-1)/2;
        else s += (mid*(mid-1)/2 ) - (mid-1-x)*(mid-x)/2;
        if(mid-1 <= y)
            s += mid*(mid-1)/2;
        else s += (mid*(mid-1)/2 ) - (mid-1-y)*(mid-y)/2;
   //     cout<<mid<<" "<<s<<"\n";
        if(s <= m-n)
        {
            ans = max(ans, mid);
            l = mid+1;
        }
        else r = mid-1;
    }
    cout<<ans+1;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

