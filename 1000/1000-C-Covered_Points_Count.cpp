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
ll ans[300000];

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
    cin>>n;
    map<ll,ll> m;
    f(0,n){
        ll a, b;
        cin>>a>>b;
        m[a]++;
        m[b+1]--;
    }
    map<ll,ll> :: iterator it, itt;
    ll c=0, d=0;
    for(it = m.begin(); it!=m.end(); it++)
    {
        c += it->second;
       // cout<<it->first<<" "<<it->second<<" "<<c<<"\n";
        //ans[c]++;
        itt = it;
        ++it;
        ans[c] += abs(it->first - itt->first);
        it--;
    }
    f(1, n+1)
        cout<<ans[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

