/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
string s;
ll ans = 0;

void rec(ll i, ll cs, ll le, bool b)
{
    if(i < 0)
        return;
 //   cout<<i+1<<" "<<ans<<"\n";
    if(s[i] == 'b')
    {
        rec(i-1, cs, le, true);
        return;
    }
    if(s[i] == 'a')
    {
        if(b)
        {
            le = (cs + 1) % mod;
            ans = (ans + le) % mod;
            cs = (cs + le) % mod;
        }
        else
        {
            ans = (ans + le) % mod;
            cs = (cs + le) % mod;
        }
        b = false;
    }
    rec(i-1, cs, le, b);
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    rec(s.length()-1, 0, 1, false);
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

