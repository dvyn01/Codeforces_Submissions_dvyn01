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
vll adj[100050];
ll s[100050],   ans, mn[100050];
bool no;

ll dfs(ll x)
{
    ll cm = 1e18;
    f(0, adj[x].size())
        cm = min(cm, dfs(adj[x][i]));
    if(cm != 1e18 && cm < s[x])
    {
        no = true;
        return 0;
    }
    mn[x] = cm;
    if(s[x] != -1)
        return s[x];
    else return mn[x];
}

void dfs2(ll x, ll cs)
{
    if(x != 1 && s[x] != -1)
    {   ans += s[x] - cs;   cs  = s[x]; }
    else if(x != 1 && mn[x] < 1e17)
    {   ans += mn[x] - cs;      cs += mn[x] - cs;   }
    else if(x == 1){  ans += s[1];   cs += s[1]; }
    f(0, adj[x].size())
        dfs2(adj[x][i], cs);
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    f(2, n+1)
    {
        ll x;
        cin>>x;
        adj[x].pb(i);
    }
    f(1, n+1)       cin>>s[i];
    ll x = dfs(1);
    if(no)
    {   cout<<-1;   return 0;   }
    dfs2(1, 0);
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

