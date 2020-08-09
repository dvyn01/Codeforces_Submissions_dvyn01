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
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k, c = 0;
    cin>>n>>k;
    ll a[40];
    memset(a, 0, sizeof(a));
    ll kk = 40;
    while(kk >= 0)
    {
        if((1LL << kk) & n)
            a[kk]++, c++;
        kk--;
    }
    if(k > n || k < c)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    c = k - c;
    for(ll j = 33; j >= 0; j--)
    {
        if(c == 0)
            break;
        if(a[j] != 0)
        {
            if(a[j] >= c)
            {
                a[j - 1] += 2 * c;
                a[j] -= c;
                c = 0;
            }
            else
            {
                a[j-1] += 2 * a[j];
                c -= a[j];
                a[j] = 0;
            }
        }
        if(c == 0)
            break;
    }
    f(0, 40)
    {
        if(a[i])
        {
            fi(0, a[i])
                cout<<(1LL << i)<<" ";
        }
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

