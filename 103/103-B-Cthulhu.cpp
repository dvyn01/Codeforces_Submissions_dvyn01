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
ll a[200], s[200], c;
vll adj[200];

void init(ll n)
{
    f(1, n+1)
    {
        a[i] = i;
        s[i] = 1;
    }
}

ll root(ll i)
{
    while(a[i] != i)
        i = a[a[a[a[a[a[i]]]]]];
    return i;
}

void unionn(ll x, ll y)
{
    ll xr = root(x), yr = root(y);
    if(xr == yr)
    {
        c++;
        return;
    }
    ll xs = s[xr], ys = s[yr];
    if(xs > ys)
    {
        a[yr] = a[xr];
        s[xr] += ys;
    }
    else{
        a[xr] = a[yr];
        s[yr] += xs;
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
 //   ios_base::sync_with_stdio(false);
 //   cin.tie(NULL);
 //   cout.tie(0);

    ll n, m;
    cin>>n>>m;
    init(n);
    f(0,m)
    {
        ll x, y;
        cin>>x>>y;
        unionn(x, y);
        adj[x].pb(y); adj[y].pb(x);
    }
    if(c == 1)
    {
        bool ok = true;
        f(1, n+1)
            if(adj[i].size() == 0)
                ok = false;
        if(ok)
            cout<<"FHTAGN!";
        else cout<<"NO";
    }
    else cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

