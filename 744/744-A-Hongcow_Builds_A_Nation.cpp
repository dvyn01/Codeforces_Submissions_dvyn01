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
ll a[100005], s[100005], e[100005];
bool b[100005] = {false};
map<ll,ll> mm;

void init(ll n)
{
    f(1, n+1)
    {
        a[i] = i;
        s[i] = 1;
        e[i] = 0;
    }
}

ll root(ll i)
{
  while(a[i] != i)
    i = a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[i]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]];         // *LESS* :-(
  return i;
}

void unionn(ll x, ll y)
{
    ll xr=root(x), yr = root(y);
    ll xs=s[xr], ys=s[yr];
    if(xr==yr){e[xr]++;  return; }
    if(xs > ys)
    {
        a[yr] = a[xr];
        s[xr] += ys;
        if(mm[x] != 0 || mm[y]!=0 || b[xr] || b[yr]) b[xr] = b[yr] = b[x] = b[y] =  true;
        ll q = e[xr]+e[yr]+1;
        e[xr] = q; e[yr] = q;
    }
    else{
          a[xr] = a[yr];
        s[yr] += xs;
        if(mm[x] != 0 || mm[y]!=0 || b[xr] || b[yr]) b[yr] = b[xr] = b[x] = b[y] = true;
        ll q = e[xr]+e[yr]+1;
        e[xr] = q; e[yr] = q;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, m, k;
    cin>>n>>m>>k;
    init(n);
    f(0,k)
    {
        ll x;
        cin>>x;
        mm[x]++;
        b[x] = true;
    }
    f(0,m)
    {
        ll x, y;
        cin>>x>>y;
        unionn(x, y);
    }
    ll c=0, ms=0, ans=0, y=0;
    f(1, n+1)
    {
        if(a[i]==i)
        {
            if(!b[i])
                {
                    c += s[i];
                    y += e[i];
                }
            if(b[i])
            {
                if(ms < s[i])
                    ms = s[i];
                ll y=s[i], z=e[i];
                ans += (y*(y-1)/2)-z;
            }
        }
    }
   // f(1, n+1){if(b[i])cout<<"1 ";else cout<<"0 ";}
    ans += ms*c;
    ans += c*(c-1)/2 - y;
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

