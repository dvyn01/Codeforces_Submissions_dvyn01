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
ll a[105][105];

void init(ll n)
{
    f(1,n+1)
    {
       for(ll j=1; j<105; j++)
            a[i][j] = j;
    }
}

ll root(ll i, ll c)
{
    while(a[c][i] != i)
        i = a[c][i];
    return i;
}

void unionn(ll x, ll y, ll c)
{
    ll rb = root(y, c);
    a[c][rb] = root(x, c);
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

    ll n, m;
    cin>>n>>m;
    init(m);
    f(0,m)
    {
        ll x, y, c;
        cin>>x>>y>>c;
        unionn(x, y, c);
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll ans=0;
        ll x, y;
        cin>>x>>y;
        f(1,m+1)
        {
            if(root(x,i) == root(y, i))
                ans++;
        }
        cout<<ans<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
