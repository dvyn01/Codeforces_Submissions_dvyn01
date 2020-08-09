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
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    pll p, ans;
    f(0, 2*n) {ll x; cin>>x;  p.pb(mp(x, i+1)); }
    sort(p.begin(), p.end());
    f(0, 2*n)
    {
        if(p[i].first != p[i+1].first)
        {
            cout<<"-1"; return 0;
        }
        ans.pb(mp(p[i].second, p[i+1].second));
        i++;
    }
    f(0, ans.size())
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

