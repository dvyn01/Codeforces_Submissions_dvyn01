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
ll a[200010];
ll f[200010], s[200010];
void init(ll n)
{
    f(1, n+1)
    {
        a[i] = i;
        s[i]=1;
    }
}

ll root(ll i)
{
    while(a[i] != i)
        i = a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[i]]]]]]]]]]]]]]]];      // * * * * * * * * //
    return i;
}

void unionn(ll x, ll y)
{
    ll xr = root(x), yr = root(y);
    if(xr != yr)
        {
            ll xs = s[xr], ys = s[yr];
            if(xs > ys){
            a[yr] = a[xr];
            s[xr] += ys;
            }
            else{
                a[xr] = a[yr];
                s[yr] += xs;
            }
        }
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, m, sum=0;
    cin>>n>>m;
    init(n);
    vll adj[n+1];
    map<ll,ll> p;
    f(0,m)
    {
        ll a, b;
        cin>>a>>b;
        f[a]++;
        f[b]++;
        unionn(a, b);
    }
    f(1, n+1)
    {
        if(a[i] == i)
            p[i] = 1;
    }
    f(1, n+1)
    {
        if(p[root(i)]==0)
            continue;
        if(f[i] != 2)
        {
            ll r = root(i);
            p[r]=0;
        }
    }
    map<ll,ll> :: iterator it;
    for(it=p.begin(); it!=p.end(); it++)
    {
        if(it->second == 1)
            sum++;
    }
    cout<<sum;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
