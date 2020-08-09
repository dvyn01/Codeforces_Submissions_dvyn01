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
ll n, m, s, ct;
vll adj[5005];
bool b[5005] = {false}, c[5005] = {false};

void dfs(ll s)
{
    b[s] = true;
    f(0, adj[s].size()){
        if(!b[adj[s][i]]){
            dfs(adj[s][i]);
        }
    }
}

void dfs1(ll s)
{
     ct++;
    c[s] = true;
    f(0, adj[s].size()){
        if(!c[adj[s][i]] && !b[adj[s][i]]){
            dfs1(adj[s][i]);
        }
    }
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

    cin>>n>>m>>s;
    f(0,m){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    dfs(s);
    ll ans=0;
    xyz :
    ll mx=0, pos=0;
    f(1, n+1)
    {
        if(!b[i]){
            ct=0;
            memset(c, false, sizeof(c));
           dfs1(i);
        //   cout<<i<<" "<<ct<<"\n";
           if(ct>mx)
           {
               mx = ct;
               pos = i;
           }
        }
    }
    if(pos != 0){
        dfs(pos);
        ans++;
       // cout<<pos<<" ";
        goto xyz;
    }
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

