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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll a[n], b[n];
    vll x, y;
    f(0, n)     {   cin>>a[i];  if(i != 0) x.pb(a[i] - a[i-1]);     }
    f(0, n)     {   cin>>b[i];  if(i != 0) y.pb(b[i] - b[i-1]);     }
    if(a[0] != b[0] || a[n-1] != b[n-1])
        cout<<"No";
    else{
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        bool ok = true;
        f(0, x.size())
        {
            if(x[i] != y[i])
            {
                ok = false;
                break;
            }
        }
        if(ok)
            cout<<"Yes";
        else cout<<"No";
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

