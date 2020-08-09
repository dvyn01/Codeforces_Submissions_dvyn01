/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
      #include <ext/pb_ds/tree_policy.hpp>

      using namespace __gnu_pbds;       */
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
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll n, m;
char s[1010][1010];
map<char, char> fckk;
ll ans, c, dp[1010][1010];


bool safe(ll x, ll y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

ll dfs(ll x, ll y)
{
    ll kk = 0;
    if(dp[x][y] != 0)
        return dp[x][y];
//    p.pb({x, y});
    dp[x][y] = 1e18;
    if(safe(x+1, y) && s[x+1][y] == fckk[s[x][y]])
        kk = max(kk, dfs(x+1, y));
    if(safe(x-1, y) && s[x-1][y] == fckk[s[x][y]])
        kk = max(kk, dfs(x-1, y));
    if(safe(x, y+1) && s[x][y+1] == fckk[s[x][y]])
        kk = max(kk, dfs(x, y+1));
    if(safe(x, y-1) && s[x][y-1] == fckk[s[x][y]])
        kk = max(kk, dfs(x, y-1));
    dp[x][y] = min(dp[x][y], kk + 1);
    return dp[x][y];
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    f(1, n+1)       fi(1, m+1)      cin>>s[i][j];
    fckk['D'] = 'I';        fckk['I'] = 'M';        fckk['M'] = 'A';        fckk['A'] = 'D';
    f(1, n+1)
    {
        fi(1, m+1)
        {
            if(s[i][j] == 'D')
            {
                c = dfs(i, j);
           //     for(int x = 1; x <= n; x++){for(int y = 1; y <= m; y++) cout<<dp[x][y]<<" ";    cout<<"\n";}
           //     fii(0, p.size())  dp[p[k].first][p[k].second] = 0;
                if(c > ans) ans = c;
                if(c >= 1e18)   break;
            }
        }
    }
  //  f(1, n+1)   {fi(1, m+1) cout<<dp[i][j]<<" ";    cout<<"\n";}
    if(ans >= 1e18)
        cout<<"Poor Inna!";
    else if(ans/4 == 0)
        cout<<"Poor Dima!";
    else cout<<ans/4;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}     