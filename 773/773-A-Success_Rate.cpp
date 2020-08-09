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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        ll x, y, p, q;
        cin>>x>>y>>p>>q;
        ll c=1;
        if(p==1 && q==1)
        {
            if(x!=y)
                cout<<"-1\n";
            else cout<<"0\n";
            continue;
        }
        ll l=1, r=1000000000, ans=1e18;
        while(l<=r)
        {
            c = (l+r)/2;
            ll a=p*c, b=q*c;
            if(a>=x && b>=y)
            {
                ll pp=a-x, qq=b-y;
                if(pp <= qq)
                {
                    ans = min(ans, qq);
                    r = c-1;
                }
                else l = c+1;
            }
            else l = c+1;

        }
        if(ans != 1e18 && ans>=0)
            cout<<ans<<"\n";
        else cout<<"-1\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

