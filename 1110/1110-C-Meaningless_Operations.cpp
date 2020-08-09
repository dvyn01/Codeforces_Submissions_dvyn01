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

    ll m[26];   memset(m, 0, sizeof(m));
    m[2] = 1;    m[3] = 1;    m[4] = 5;    m[5] = 1;    m[6] = 21;    m[7] = 1;    m[8] = 85;    m[9] = 73;    m[10] = 341;    m[11] = 89;    m[12] = 1365;    m[13] = 1;    m[14] = 5461;    m[15] = 4681;    m[16] = 21845;    m[17] = 1;    m[18] = 87381;    m[19] = 1;    m[20] = 349525;    m[21] = 299593;    m[22] = 1398101;    m[23] = 178481;    m[24] = 5592405;    m[25] = 1082401;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll k = n+1;
        if(__builtin_popcount(k) == 1)
        {
            ll kk = 0;
            while((1LL << kk) < n)
                kk++;
            cout<<m[kk]<<"\n";
        }
        else
        {
            ll kk = 0;
            while((1LL << kk) <= n)
                kk++;
            ll ans = (1LL << kk) - 1;
            cout<<ans<<"\n";
        }
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

