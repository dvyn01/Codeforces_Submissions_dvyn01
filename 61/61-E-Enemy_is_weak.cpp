/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
//      #include <ext/pb_ds/assoc_container.hpp>
//      #include <ext/pb_ds/tree_policy.hpp>

//      using namespace __gnu_pbds;
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
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll n, tr[4000050], a[1000050], tr2[4000050];

void update(ll node, ll start, ll end, ll in, ll v)
{
    if(start == end)
    {
        tr[node] += v;
        return;
    }
    ll mid = (start + end) >> 1;
    if(start <= in && in <= mid)
        update(2*node, start, mid, in, v);
    else update(2*node+1, mid+1, end, in, v);
    tr[node] = tr[2*node] + tr[2*node+1];
}

void update2(ll node, ll start, ll end, ll in, ll v)
{
    if(start == end)
    {
        tr2[node] += v;
        return;
    }
    ll mid = (start + end) >> 1;
    if(start <= in && in <= mid)
        update2(2*node, start, mid, in, v);
    else update2(2*node+1, mid+1, end, in, v);
    tr2[node] = tr2[2*node] + tr2[2*node+1];
}

ll query(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end || start > r || end < l || l > r)
        return 0;
    if(start >= l && end <= r)
        return tr[node];
    ll mid = (start + end) >> 1;
    return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
}

ll query2(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end || start > r || end < l || l > r)
        return 0;
    if(start >= l && end <= r)
        return tr2[node];
    ll mid = (start + end) >> 1;
    return query2(2*node, start, mid, l, r) + query2(2*node+1, mid+1, end, l, r);
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<ll, ll> m;
    cin>>n;
    f(1, n+1){  cin>>a[i];  m[a[i]] = i;    }
    ll c = 1;
    for(auto it : m)
        a[it.second] = c++;
    f(2, n+1)   update(1, 1, n, a[i], 1);
    update2(1, 1, n, a[1], 1);
    ll ans = 0;
    f(2, n+1)
    {
        update(1, 1, n, a[i], -1);
        ll k = query(1, 1, n, 1, a[i] - 1) * query2(1, 1, n, a[i]+1, c);
        ans += k;
        update2(1, 1, n, a[i], 1);
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

