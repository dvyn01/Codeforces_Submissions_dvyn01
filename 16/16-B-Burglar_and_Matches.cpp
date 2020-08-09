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

multimap<ll,ll> m;

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, q;
    cin>>n>>q;
    f(0,q){
        ll a, b;
        cin>>a>>b;
        m.insert(mp(b, a));
    }
    ll s=0, b=0;
    multimap<ll,ll> :: iterator it;
    for(it= --m.end(); ; it--){
          //  cout<<it->first<<" "<<it->second<<"\n";
            if(n<=0) break;
        if(b + it->second <= n){
            b += it->second;
            s += (it->first)*(it->second);
        }
        else{
            ll p = n - b;
            s += (it->first)*p;
            break;
            }
        if(it == m.begin()) break;
    }
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

