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
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    ll a[n];
    pll p;
    f(0, n)
    {
        cin>>a[i];
        p.pb(mp(-1*a[i], i));
    }
    sort(p.begin(), p.end());
    f(0, n) p[i].first *= -1;
    bool b[n] = {false};
    ll c=1, pos=0, j=0;
    if(a[0]==0){cout<<-1; return 0; }
    pll ans;
    b[0] = true;
    while(c<n && j<n)
    {
        ll x = a[pos];
        ll e=0;
        f(0, n)
        {
            if(e == a[pos])
                break;
            if(p[i].second == pos)
                continue;
            if(b[p[i].second])
                continue;
            b[p[i].second] = true;
            c++;
            e++;
            ans.pb(mp(pos+1, p[i].second+1));
        }
        pos = p[j++].second;
        if(pos==0)
            pos = p[j++].second;
    }
    f(0, n)
    {
        if(!b[i])
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<ans.size()<<"\n";
    f(0, ans.size())    cout<<ans[i].first<<" "<<ans[i].second<<"\n";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

