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
ll a[100050], t[200050];
vll v[100050];
map<ll, ll> m;

void create(ll node, ll start, ll end)
{
    if(start == end)
    {
        t[node] = a[start];
        return;
    }
    ll mid = (start + end) >> 1;
    create(2*node, start, mid);
    create(2*node+1, mid+1, end);
    t[node] = __gcd(t[2*node], t[2*node+1]);
}

ll query(ll node, ll start, ll end, ll l, ll r)
{
    if(start > r || end < l)
        return 0;
    if(start >= l && end <= r)
        return t[node];
    ll mid = (start + end) >> 1;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return __gcd(p1, p2);
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, c = 1;
    cin>>n;
    f(1, n+1)
    {
        cin>>a[i];
        if(m[a[i]] == 0)
            m[a[i]] = c++;
        v[m[a[i]]].pb(i);
    }
    create(1, 1, n);
    ll q;
    cin>>q;
    while(q--)
    {
        ll l, r;
        cin>>l>>r;
        ll g = query(1, 1, n, l, r);
        ll k = m[g];
        ll k1 = lower_bound(v[k].begin(), v[k].end(), l) - v[k].begin();
        ll k2 = upper_bound(v[k].begin(), v[k].end(), r) - v[k].begin();
        k2--;
        ll f = k2 - k1 + 1;
        if(f < 0)       f = 0;
        cout<<r - l + 1 - f<<"\n";
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

