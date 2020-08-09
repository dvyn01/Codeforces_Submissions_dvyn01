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

    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll z = 0, o = 0, t = 0;
    f(0, s.length())
    {
        if(s[i] == '0')
            z++;
        else if(s[i] == '1')
            o++;
        else t++;
    }
    if(z == o && o == t)
    {
        cout<<s;
        return 0;
    }
    ll x = n/3;
    if(z < x)
    {
        f(0, s.length())
        {
            ll k = s[i] - '0';
            if(k == 1 && o > x)
            {
                s[i] = '0';
                z++;
                o--;
            }
            else if(k == 2 && t > x)
            {
                s[i] = '0';
                z++;
                t--;
            }
            if(z == x)
                break;
        }
    }
    if(o < x)
    {
        ll k1 = 0, k2 = 0;
        f(0, n)
        {
            if(o == x)
                break;
            if(k1 < x && s[i] == '0')
            {
                k1++;   continue;
            }
            else if(s[i] == '0')
            {
                s[i] = '1';
                o++;
                z--;
            }
            if(o == x)
                break;
        }
        f(0, n)
        {
            if(o == x)
                break;
            if(s[i] == '2')
            {
                s[i] = '1';
                o++;
                t--;
            }
            if(o == x || t == x)
                break;
        }
    }
 //   cout<<s<<" ";
    if(t < x)
    {
        ll k1 = 0, k2 = 0;
        f(0, n)
        {
            if(t == x)
                break;
            if(k1 < x && s[i] == '0')
            {
                k1++;   continue;
            }
            else if(s[i] == '0')
            {
                s[i] = '2';
                t++;
                z--;
            }
            if(t == x)
                break;
        }
        f(0, n)
        {
            if(t == x)
                break;
            if(k2 < x && s[i] == '1')
            {
                k2++;   continue;
            }
            else if(s[i] == '1')
            {
                s[i] = '2';
                t++;
                o--;
            }
            if(t == x)
                break;
        }
    }
    cout<<s;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

