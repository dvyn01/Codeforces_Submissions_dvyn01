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
 //    freopen("output.txt", "wt", stdout); *No Need*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    cout<<fixed<<setprecision(10);
    ld y = 10;
    while(t--)
    {
        ld n;
        cin>>n;
        ld x = 0.0, pr = 1.0, ans = -1;
        while(1)
        {
            ld k = n-x;
   //         cout<<x<<" "<<n-x<<" "<<x * (n-x)<<" "<<pr<<" "<<abs(x * k - n)<<"\n";
            if(pr < 0.000000000000000000000000000000001)
                break;
            if(abs(x * k - n) <= 0.0000001)
            {
                ans = x;
                break;
            }
            if(x * k < n)
            {
                while(1)
                {
                    ld k1 = (x+pr) * (k-pr),    k2 = x * k;
                    if(abs(k1 - n) < abs(k2 - n))
                    {
                        x += pr;
                    }
                    else break;
                }
            }
            else
            {
                while(1)
                {
                    ld k1 = (x-pr) * (k+pr),    k2 = x * k;
                    if(abs(k1 - n) < abs(k2 - n))
                    {
                        x -= pr;
                    }
                    else break;
                }
            }
            pr /= 2;
        }
        if(ans == -1)
        {
            cout<<"N\n";
            continue;
        }
        cout<<"Y "<<ans<<" "<<n-ans<<"\n";
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

