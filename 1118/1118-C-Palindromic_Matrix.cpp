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
set< pair<ll, ll>, greater< pair<ll, ll> > > s;

ll a[1005];

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, y;
    bool ok = true;
    cin>>n;
    ll ans[n+1][n+1];
    ll x = n/2;
    f(0, n*n)       cin>>y,     a[y]++;
    f(1, 1001)  if(a[i])    s.insert({a[i], i});
    f(1, x+1)
    {
        fi(1, x+1)
        {
            auto it = s.begin();
            if(it -> first < 4)
            {
                ok = false;
                break;
            }
            ll k = it -> second, k1 = it -> first;
            ans[i][j] = k;      ans[i][n-j+1] = k;  ans[n-i+1][j] = k;  ans[n-i+1][n-j+1] = k;
            k1 -= 4;
            s.erase(s.begin());
            if(k1 > 0)
            s.insert({k1, k});
        }
    }
    if(n & 1)
    {
        x = n / 2 + 1;
        f(1, n/2 + 1)
        {
           auto it = s.begin();
           if(it -> first < 2)
           {
                ok = false;
                break;
           }
           ll k = it -> second, k1 = it -> first;
           ans[x][i] = k;   ans[x][n-i+1] = k;
           k1 -= 2;
           s.erase(s.begin());
           if(k1 > 0)
            s.insert({k1, k});
        }
        f(1, n/2 + 1)
        {
           auto it = s.begin();
           if(it -> first < 2)
           {
                ok = false;
                break;
           }
           ll k = it -> second, k1 = it -> first;
           ans[i][x] = k;   ans[n-i+1][x] = k;
           k1 -= 2;
           s.erase(s.begin());
           if(k1 > 0)
            s.insert({k1, k});
        }
        if(ok)
        {
            auto it = s.begin();
            ans[x][x] = it -> second;
        }
    }
    if(!ok)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    f(1, n+1)
    {
        fi(1, n+1)      cout<<ans[i][j]<<" ";
        cout<<"\n";
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

