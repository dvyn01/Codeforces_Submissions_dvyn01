/*
          * AUTHOR : Divyanshu *
*/  

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll c[1000050], a[200050], ans[200050], cs, cl, cr, n, q, block_size;
pair<pair<ll, ll>, ll> p[200050];

void add(ll x)
{
    cs -= c[x] * c[x] * x;
    c[x]++;
    cs += c[x] * c[x] * x;
}

void removee(ll x)
{
    cs -= c[x] * c[x] * x;
    c[x]--;
    cs += c[x] * c[x] * x;
}

bool compare(const pair<pair<ll, ll>, ll> &x, const pair<pair<ll, ll>, ll> &y)
{
    ll bx = x.first.first / block_size, by = y.first.first / block_size;
    if(bx != by)
        return bx < by;
    return x.first.second < y.first.second;
}

void solve()
{
    ll cl = 0, cr = -1;
    ll lr = -1, l1 = -1;
    f(0, q)
    {
        ll l = p[i].first.first-1, r = p[i].first.second-1;
        if(l > lr && lr != -1)
        {
            while(l1 <= lr)
                removee(a[l1++]);
            cl = l;     cr = l - 1;
        }
        while(cl < l)
        {
            removee(a[cl]);
            cl++;
        }
        while(cl > l)
        {
            add(a[cl-1]);
            cl--;
        }
        while(cr > r)
        {
            removee(a[cr]);
            cr--;
        }
        while(cr < r)
        {
            add(a[cr+1]);
            cr++;
        }
        ans[p[i].second] = cs;
        lr = cr;    l1 = cl;
    }
    f(1, q+1)   cout<<ans[i]<<"\n";
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

    cin>>n>>q;
    f(0, n) cin>>a[i];
    block_size = sqrt(n);
    f(0, q)
    {
        cin>>p[i].first.first>>p[i].first.second;
        p[i].second = i+1;
    }
    sort(p, p+q, compare);
    solve();

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}