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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, k, m;
    map<string,ll> p;
    cin>>n>>k>>m;
    string s[n+1];
    f(1,n+1) cin>>s[i];
    ll c[n+1];
    f(1,n+1) cin>>c[i];
    while(k--)
    {
        ll x;
        cin>>x;
        ll a[x], minn=1e18;
        f(0,x){
            cin>>a[i];
            if(c[a[i]] < minn)
                minn = c[a[i]];
        }
      //  cout<<k<<"k "<<minn<<"\n";
        f(0,x) p[s[a[i]]] = minn;
    }
    ll sum=0;
    f(0,m)
    {
        string z;
        cin>>z;
       // cout<<sum<<" ";
        sum += p[z];
    }
    cout<<sum;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

