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

    string s;
    cin>>s;
    ll k;
    cin>>k;
    ll q = 0, ss = 0, c = 0;
    f(0, s.length())
    {
        if(s[i] == '?') q++;
        else if(s[i] == '*')    ss++;
        else c++;
    }
    if(c - (ss + q) > k)
    {
        cout<<"Impossible";
        return 0;
    }
    if(k <= c)
    {
        ll x = c - k;
        string ans;
        f(0, s.length())
        {
            if(i != s.length() - 1 && s[i+1] == '?' || s[i+1] == '*')
            {
                if(x > 0)
                {   x--;    continue;   }
            }
            if(s[i] == '?' || s[i] == '*')  continue;
            ans += s[i];
        }
        cout<<ans;
        return 0;
    }
    else if(k > c && ss == 0)
    {   cout<<"Impossible";     return 0;   }
    else
    {
        string ans;
        ll x = k - c;
        f(0, s.length())
        {
            if(i != s.length() - 1 && s[i+1] == '*' && s[i] != '*' && s[i] != '?')
            {
                while(x != 0)
                    ans += s[i],    x--;
                ans += s[i];
                continue;
            }
            if(s[i] != '*' && s[i] != '?')
                ans += s[i];
        }
        cout<<ans;
    }


    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

