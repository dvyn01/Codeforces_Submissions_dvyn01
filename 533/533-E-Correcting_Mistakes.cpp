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
    string s, t;
    cin>>s>>t;
    ll k = 0;
    f(0, n)     if(s[i] != t[i])    k++;
    if(k == 1)
    {
        cout<<2;
        return 0;
    }
    string z1 = "", z = "";
    f(0, n)
    {
        if(s[i] == t[i])
        {
            z += s[i];
            z1 += s[i];
            continue;
        }
        z += s[i];
        fi(i, n)  z += t[j];
        z1 += t[i];
        fi(i, n)  z1 += s[j];
        break;
    }
    bool ok = false;
    ll cp = 0, k1 = 0, k2 = 0;
    f(0, n+1)
    {
        if(s[cp] != z[i])
        {
            k1++;   continue;
        }
        cp++;
    }
    cp = 0;
    f(0, n+1)
    {
        if(t[cp] != z[i])
        {
            k2++;   continue;
        }
        cp++;
    }
  //  cout<<z<<" "<<k1<<" "<<k2<<"\n";
    ll xx = 0;
    if(k1 == 1 && k2 == 1)
    {
        xx++;
    }
    cp = 0, k1 = 0, k2 = 0;
    f(0, n+1)
    {
        if(s[cp] != z1[i])
        {
            k1++;   continue;
        }
        cp++;
    }
    cp = 0;
    f(0, n+1)
    {
        if(t[cp] != z1[i])
        {
            k2++;   continue;
        }
        cp++;
    }
    if(k1 == 1 && k2 == 1)
    {
        xx++;
    }
    cout<<xx;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
