/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
//      #include <ext/pb_ds/assoc_container.hpp>
//      #include <ext/pb_ds/tree_policy.hpp>

//      using namespace __gnu_pbds;
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

    string z;
    cin>>z;
    ll n = z.length();
    ll s[n+1],  e[n+1];
    memset(s, 0, sizeof(s));    memset(e, 0, sizeof(e));
    bool b[n+1][n+1];
    memset(b, false, sizeof(b));
    f(0, n)
        s[i] = 1,    e[i] = 1,    b[i][i] = true;
    f(0, n-1)
    {
        if(z[i] == z[i+1])
        {
            s[i]++;
            e[i+1]++;
            b[i][i+1] = true;
        }
    }
    fii(3, n+1)
    {
        f(0, n-k+1)
        {
            ll j = i + k - 1;
            if(b[i+1][j-1] && z[i] == z[j])
            {
                s[i]++;
                e[j]++;
                b[i][j] = true;
            }
        }
    }
    ll ans = 0;
 //   f(0, n)     cout<<s[i]<<" "<<e[i]<<"\n";
    fr(n-1, 0)
        s[j] += s[j+1];
 //   f(0, n)     cout<<s[i]<<" "<<e[i]<<"\n";
    f(0, n)
        ans += e[i] * s[i+1];
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

