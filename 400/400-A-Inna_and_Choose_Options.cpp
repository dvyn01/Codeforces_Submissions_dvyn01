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
    cout.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        pll ans;
        f(1, 13)
        {
            if(12 % i != 0)
                continue;
            ll jump = 12 / i;
            fi(0, i)
            {
                bool ok = true;
                ll k = j;
          //      cout<<"\n\n\n"<<i<<"\n";
               while(k < 12)
               {
           //        cout<<k<<" "<<s[k]<<"\n";
                   if(s[k] != 'X')
                   {
                       ok = false;
                       break;
                   }
                   k += i;
               }
               if(ok)
               {
                   ans.pb(mp(12/i, i));
                   break;
               }
            }
        }
        cout<<ans.size()<<" ";
        sort(ans.begin(), ans.end());
        f(0, ans.size())    cout<<ans[i].first<<"x"<<ans[i].second<<" ";
        cout<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

