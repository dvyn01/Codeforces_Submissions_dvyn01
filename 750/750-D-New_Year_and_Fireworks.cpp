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
bool b[401][401];
bool dp[401][401][35][9];
ll n, a[35], ans, dx[8][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};
/*
    0 : N       x, y + 1
    1 : NE      x + 1, y + 1
    2 : E       x + 1, y
    3 : SE      x + 1, y - 1
    4 : S       x, y - 1
    5 : SW      x - 1, y - 1
    6 : W       x - 1, y
    7 : NW      x - 1, y + 1
*/

void rec(ll x, ll y, ll in, ll cd)
{
    if(in >= n)
        return;
  //  cout<<in<<" "<<cd<<" "<<x<<" "<<y<<"\n";
    if(dp[x][y][in][cd])
        return;
    dp[x][y][in][cd] = true;
    f(1, a[in] + 1)
    {
        x += dx[cd][0];
        y += dx[cd][1];
        if(!b[x][y])
            b[x][y] = true, ans++;
    }
    rec(x, y, in + 1, (cd + 7) % 8);
    rec(x, y, in + 1, (cd  + 1) % 8);
}


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    f(0, n)       cin>>a[i];
    memset(b, false, sizeof(b));
    rec(200, 200, 0, 0);
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
