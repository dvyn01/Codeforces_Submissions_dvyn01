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

    ll n;
    cin>>n;
    ll a[n];
    ll ans[n];
    vll v[n+1];
    bool z = false, nz = false;
    f(0, n)     {   cin>>a[i];      if(a[i] == 0)   z = true;   else nz = true;   v[a[i]].pb(i);  }
    if(z && nz)
    {
        cout<<"Impossible";
        return 0;
    }
    if(z)
    {
        cout<<"Possible\n";
        f(1, n+1)   cout<<1<<" ";
        return 0;
    }
    ll mx = 1;
    map<ll, ll> m;
    memset(ans, -1, sizeof(ans));
    f(0, n)
    {
        if(ans[i] == -1)
        {
            ans[i] = mx;
            ll k = n - a[i];
            if(v[a[i]].size() < k)
            {
                cout<<"Impossible";
                return 0;
            }
            ll c = 0;
            fi(1, 1000001)
            {
                if(c == k - 1)
                    break;
                if(j >= v[a[i]].size())
                {
                    cout<<"Impossible";
                    return 0;
                }
                if(ans[v[a[i]][j]] != -1)
                    continue;
                ans[v[a[i]][j]] = mx;
                c++;
                if(c == k - 1)
                    break;
            }
            mx++;
        }
    }
    cout<<"Possible\n";
    f(0, n)     cout<<ans[i]<<" ";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


