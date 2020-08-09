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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, a, b;
    cin>>n>>m;
    if(n == 1)
    {
        cout<<"NO";
        return 0;
    }
    if(m == 0)
    {
        cout<<"YES\n";
        ll c = 1;
        f(0, n) cout<<c++<<" ";
        cout<<"\n";
        cout<<"1 1 ";
        c = 3;
        f(0, n-2)       cout<<c++<<" ";
        return 0;
    }
    pll p;
    ll ct[n+1];
    memset(ct, 0, sizeof(ct));
    vll v[n+1];
    f(0, m)     cin>>a>>b,      v[a].pb(b),     v[b].pb(a),     ct[a]++, ct[b]++;
    bool r[n+1] = {false};
    ll k = 1;
    while(k <= n && ct[k] >= n-1)
        k++;
    if(k == n+1)
    {
        cout<<"NO";
        return 0;
    }
    r[k] = true;
    ll ans[n+1];        memset(ans, -1, sizeof(ans));
    ll ans2[n+1];       memset(ans2, -1, sizeof(ans2));
    f(0, v[k].size())
        r[v[k][i]] = true;
    ans[k] = 1;
    ans2[k] = 1;
    f(1, n+1)
    {
        if(!r[i])
        {
            ans2[i] = 2;
            ans[i] = 1;
            break;
        }
    }
    ll c = 3;
    f(1, n+1)
    {
        if(ans[i] == -1)
        {
            ans[i] = c;
            ans2[i] = c++;
        }
    }
    cout<<"YES\n";
    f(1, n+1)     cout<<ans2[i]<<" ";
    cout<<"\n";
    f(1, n+1)       cout<<ans[i]<<" ";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

