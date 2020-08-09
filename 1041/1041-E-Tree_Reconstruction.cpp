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
    map<ll, ll> m;
    vll nv;
    f(0, n-1)
    {
        ll x, y;
        cin>>x>>y;
        m[x]++;     m[y]++;
    }
    if(m[n] != n-1 || m[n-1] == 0)
    {
        cout<<"NO";
        return 0;
    }
    fr(n, 0)
        if(!m[j])
            nv.pb(j);
    ll cp = 0;
    pll ans;
    for(auto it = --(--m.end()); it != m.begin(); --it)
    {
        if(it -> second == 0)
            continue;
        ll k = it -> second - 1, e = it -> first;
    //    cout<<e<<" "<<k<<"\n\n\n";
        ll lea = -1;
        while(k--)
        {
            if(cp == nv.size() || nv[cp] > e)
            {
                cout<<"NO";
                return 0;
            }
            if(lea == -1)
                ans.pb(mp(e, nv[cp]));
            else ans.pb(mp(lea, nv[cp]));
       //     cout<<e<<" "<<nv[cp]<<"\n";
            lea = nv[cp];
            cp++;
        }
        if(lea != -1)
        {
            ans.pb(mp(n, lea));
       //     cout<<lea<<" "<<n<<"\n";
        }
        else { // cout<<n<<" "<<e<<"\n";
                ans.pb(mp(n, e));   }
    }
    cout<<"YES\n";
    f(0, ans.size())
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

