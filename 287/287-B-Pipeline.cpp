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

    ll n, k;
    cin>>n>>k;
    if(n > k*(k-1)/2+1)
    {
        cout<<-1;
        return 0;
    }
    ll l=1, h=k-1;
    ll ans = 1e18;
    ll x = (k*(k-1)/2+1) - n;
    if(x==0) {cout<<k-1; return 0; }
    while(l<=h)
    {
        ll mid = (l+h)/2;
        if(mid*(mid+1)/2+1 >= x)
        {
         //   cout<<x<<" "<<mid*(mid+1)/2+1<<" "<<mid<<"\n";
            if(mid*(mid+1)/2+1 - x < 2)
            {
                ans = mid+1;
                break;
            }
            ans = min(ans, mid);
            h = mid-1;
        }
        else    l = mid+1;
    }
    cout<<k-ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

