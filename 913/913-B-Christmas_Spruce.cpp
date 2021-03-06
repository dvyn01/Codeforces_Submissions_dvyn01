/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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
    vll adj[n+1];
    f(2, n+1)
    {
        ll p;
        cin>>p;
        adj[p].pb(i);
    }
    bool ok = true;
    f(1, n+1)
    {
        if(adj[i].size()>0 && adj[i].size()<3)
        {
            ok = false; break;
        }
        if(adj[i].size() >= 3)
        {
            ll c=0;
            fi(0, adj[i].size())
                if(adj[adj[i][j]].size() == 0)
                    c++;
            if(c < 3)
            {
                ok = false;
                break;
            }
        }
    }
    if(ok)  cout<<"Yes";
    else cout<<"No";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

