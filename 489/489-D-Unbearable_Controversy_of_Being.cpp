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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    vll v[3005];
    ll n, m, c=0, ans=0;
    cin>>n>>m;
    f(0,m)
    {
        ll a, b;
        cin>>a>>b;
        v[a].pb(b);
    }
    f(1,n+1)
    {
        map<ll,ll> p;
        for(ll j=0; j<v[i].size(); j++)
        {   c=0;
            for(ll k=0; k<v[v[i][j]].size(); k++)
            {
                if(v[v[i][j]][k] != i){
                p[v[v[i][j]][k]]++;
                }
            }
        }
        map<ll,ll> :: iterator it;
        for(it=p.begin(); it!=p.end(); it++)
            ans += (it->second)*(it->second-1)/2;
    }
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

