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
#define fr(a,b) for(ll i=a; i>=b; i--)
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

    ll n, y = 0;
    cin>>n;
    map<ll, ll> fcuk;
    map<ll, ll> m;
    bool OkaY[n+1];
    memset(OkaY, false, sizeof(OkaY));
    fi(0, n)
    {
        string s;
        cin>>s;
        bool ok = true;
        ll o = 0, c = 0;
        f(0, s.length())
        {
            if(s[i] == '(')
               o++;
            else c++;
            if(c > o)
            {
                ok = false;
                break;
            }
        }
        if(ok && o != c)
        {
            m[o - c]++, OkaY[j+1] = true;
            fcuk[j+1] = o - c;
        }
        else if(!ok)
        {
            ok = true;
            o = 0;  c = 0;
            fr(s.length() - 1, 0)
            {
                if(s[i] == '(')
               o++;
            else c++;
            if(o > c)
            {
                ok = false;
                break;
            }
            }
             if(ok && o != c)
        {
            m[o - c]++, OkaY[j+1] = true;
            fcuk[j+1] = o - c;
        }
        }
        else    y++;
    }
    ll ans = 0;
    f(1, n+1)
    {
        if(OkaY[i] && m[fcuk[i] * -1] != 0)
            ans++,  m[fcuk[i] * -1]--;
    }
    cout<<ans/2 + y / 2;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

