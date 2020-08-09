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
string s;

struct tr{
    ll lc = 0, rc = 0, tc = 0;
}tre[4000050];      // Again !!!

struct tr neww()
{
    struct tr temp;
    return temp;
}

void create(ll node, ll start, ll end)
{
    if(start == end)
    {
        if(s[start] == '(')
            tre[node].lc++;
        else tre[node].rc++;
        return;
    }
    ll mid = (start + end) / 2;
    create(2*node+1, start, mid);
    create(2*node+2, mid+1, end);
    tre[node].tc = tre[2*node+1].tc + tre[2*node+2].tc;
    ll k = min(tre[2*node+1].lc,   tre[2*node+2].rc);
    tre[node].tc += 2*k;
    tre[node].lc = tre[2*node+1].lc + tre[2*node+2].lc - k;
    tre[node].rc = tre[2*node+1].rc + tre[2*node+2].rc - k;
}

struct tr query(ll node, ll start, ll end, ll l, ll r)
{
    if(start > r || end < l)
        return neww();
    if(start >= l && end <= r)
        return tre[node];
    ll mid = (start + end) / 2;
    struct tr p1 = query(2*node+1, start, mid, l, r);
    struct tr p2 = query(2*node+2, mid+1, end, l, r);
    struct tr temp;
    temp.tc = p1.tc + p2.tc;
    ll k = min(p1.lc, p2.rc);
    temp.tc += 2*k;
    temp.lc = p1.lc + p2.lc - k;
    temp.rc = p1.rc + p2.rc - k;
    return temp;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    ll q;
    cin>>q;
    ll n = s.length();
    create(0, 0, n - 1);
    while(q--)
    {
        ll l, r;
        cin>>l>>r;
        l--;        r--;
        struct tr temp = query(0, 0, n-1, l, r);
        cout<<temp.tc<<"\n";
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

