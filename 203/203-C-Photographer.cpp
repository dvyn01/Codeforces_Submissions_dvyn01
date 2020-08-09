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

    ll n, d;
    cin>>n>>d;
    ll a, b;
    cin>>a>>b;
    pll p;
    f(0,n){
        ll x, y;
        cin>>x>>y;
        p.pb(mp(x*a+y*b, i+1));
    }
    sort(p.begin(), p.end());
    vll ans;
    f(0,n){
        if(p[i].first <= d){
            ans.pb(p[i].second);
            d -= p[i].first;
        }
        else break;
    }
    cout<<ans.size()<<"\n";
    f(0, ans.size()) cout<<ans[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
