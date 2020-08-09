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

    ll t;
    cin>>t;
    while(t--)
    {
        ll n, x, y;
        cin>>n;
        vector<pair<pair<ll, ll>, ll>> p;
        f(0, n) cin>>x>>y,      p.pb(mp(mp(x, y), i+1));
        ll ans[n+1];        memset(ans, 0, sizeof(ans));
        sort(p.begin(), p.end());
        ll cm = p[0].first.second;
        bool ok = false;
        ans[p[0].second] = 1;
        f(1, p.size())
        {
            if(p[i].first.first > cm)
            {
                ok = true;
                break;
            }
            ans[p[i].second] = 1;
            cm = max(cm, p[i].first.second);
        }
        if(!ok)
            cout<<"-1\n";
        else
        {
            f(1, n+1)
            {
                if(ans[i] == 1)
                    cout<<1<<" ";
                else cout<<"2 ";
            }
            cout<<"\n";
        }
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

