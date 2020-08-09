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

bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return a.second < b.second;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, m;
    cin>>n>>m;
    pll p;
    ll v[n][m];
    f(0, n)
    {
        fi(0, m)  cin>>v[i][j];
    }
    f(0,n) p.pb(mp(i+1, i+1));
    f(0, m)
    {
        ll l=1;
        fi(0, n-1)
        {
            if(v[j+1][i] >= v[j][i])
            {
                p.pb(mp(j+2, l));
                continue;
            }
            l = j+2;
        }
    }
    sort(p.begin(), p.end());
  //  f(0, p.size()) cout<<p[i].first<<" "<<p[i].second<<"    "<<i<<"\n";
  //  cout<<"\n\n\n";
    ll k;
    cin>>k;
    f(0, k)
    {
        ll l, r;
        cin>>l>>r;
        pair<ll,ll> pp = mp(r, l);
        ll in = lower_bound(p.begin(), p.end(), pp) - p.begin();
        if(in == p.size()){cout<<"No\n"; continue;}
    //    cout<<in<<"->";
        pp = mp(1e18, l);
        in = lower_bound(p.begin()+in, p.end(), pp, compare) - p.begin();
        if(p[in].second > l) in--;
      //  cout<<in<<"\n";
        if(in == p.size() || in<0){cout<<"No\n"; continue;}
        if(p[in].first>=r && p[in].second<=l) cout<<"Yes\n";
        else cout<<"No\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
