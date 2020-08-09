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
vll adj[100000];
ll c=0;
ll cc[100000] = {0};
bool b[100000] = {false};

void dfs(ll root)
{
   // cout<<root<<" ";
    ll j = cc[root];
    b[root] = true;
    f(0, adj[root].size())
    {
        if(!b[adj[root][i]] && cc[adj[root][i]] != j)
                c++;
        dfs(adj[root][i]);
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    f(2, n+1)
    {
        ll x;
        cin>>x;
        adj[x].pb(i);
    }
    f(1, n+1) cin>>cc[i];
    dfs(1);
    cout<<c+1;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

