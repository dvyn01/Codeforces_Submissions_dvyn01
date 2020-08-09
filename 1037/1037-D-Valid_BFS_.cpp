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
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
set<ll> adj[200050];
map<ll, ll> m;
ll a[200050], c;

bool bfs()
{
    queue<ll> q;
    q.push(1);
    c++;
    while(!q.empty())
    {
        ll p = q.front();
        q.pop();
        ll x = adj[p].size()-1;
        if(p==1)    x++;
        f(0, x)
        {
            if(adj[p].find(a[c]) == adj[p].end())
                return false;
            q.push(a[c++]);
        }
    }
    return true;
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

    ll n;
    cin>>n;
    f(0, n-1)
    {
        ll x, y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    map<ll, ll> mm;
    bool ok = true;
    f(0, n) {   cin>>a[i];  if(m[a[i]]) ok=false; m[a[i]]++; }
    if(a[0] != 1 || !ok){
        cout<<"No";
        return 0;
    }
    if(n==1 && a[0]==1)
    {
        cout<<"Yes";
        return 0;
    }
    if(bfs())
        cout<<"Yes";
    else cout<<"No";


     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

