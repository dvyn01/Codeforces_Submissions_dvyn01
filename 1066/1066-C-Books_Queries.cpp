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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    map<ll, ll> l, r;
    cin>>q;
    ll lm = 0, rm = 0;
    while(q--)
    {
        char c;     ll x;
        cin>>c>>x;
        if(c == 'L')
        {
            lm++;
            l[x] = lm;
        }
        else if(c == 'R')
        {
            rm++;
            r[x] = rm;
        }
        else
        {
            if(l[x])
                cout<<min(lm - l[x], l[x] + rm - 1)<<"\n";
            else
                cout<<min(rm - r[x], r[x] + lm - 1)<<"\n";
        }
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

