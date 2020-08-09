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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    bool b[1005] = {false};
    ll n;
    cin>>n;
    ll a[n];
    f(0,n) cin>>a[i];
    vll ans;
    for(ll i=n-1; i>=0; i--)
    {
        if(!b[a[i]])
        {
            ans.pb(a[i]);
            b[a[i]] = true;
        }
    }
    cout<<ans.size()<<"\n";
    for(ll i=ans.size()-1; i>=0; i--)
        cout<<ans[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

