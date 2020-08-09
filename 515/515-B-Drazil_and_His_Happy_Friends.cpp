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
    ll v[200] = {0};
    ll n, m;
    cin>>n>>m;
    ll h = __gcd(n,m);
    f(0,2)
    {
        ll x;
        cin>>x;
        while(x--)
        {
            ll y;
            cin>>y;
            v[y%h] = 1;
        }
    }
    f(0, h)
    {
        if(!v[i])
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

