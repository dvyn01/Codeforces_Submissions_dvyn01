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
ll n, k;

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    string s;
    cin>>s;
    if(k == 2)
    {
        ll c = 0, ans;
        string z1, z2;
        f(0, s.length())
        {
            if(i & 1)
            {   z1 += 'A';     z2 += 'B';  }
            else
            {   z1 += 'B';  z2 += 'A'; }
            if(i&1 && s[i] == 'A')
                c++;
            else if(!(i & 1) && s[i] == 'B')
                c++;
        }
        ans = c;
        c = 0;
        f(0, s.length())
        {
            if(i&1 && s[i] == 'B')
                c++;
            else if(!(i & 1) && s[i] == 'A')
                c++;
        }
        if(c > ans)
            cout<<s.length() - c<<"\n"<<z2;
        else cout<<s.length() - ans<<"\n"<<z1;
        return 0;
    }
    ll cl = 0, ans = 0;
    f(0, s.length())
    {
        if(i != s.length() - 1 && s[i] == s[i+1])
        {
            cl = 1;
            ll jj = i;
            while(jj != s.length() - 1 && s[jj] == s[jj+1])
                cl++, jj++;
            ans += (cl / 2);
            if(i == s.length() || cl&1)
            {
       //         cout<<"odd\n";
                i++;
                char cc = 'A';
                if(s[i] == 'A')
                    cc = 'B';
                while(i <= jj)
                    s[i] = cc,  i += 2;
                i = jj;
            }
            else
            {
     //           cout<<"Even\n";
                i++;
                char a1 = s[i],     a2 = '*';
                if(jj != s.length() - 1)
                    a2 = s[jj+1];
                char cc;
                fi(0, k)
                {
                    if(char('A' + j) != a1 && char('A' + j) != a2)
                    {
                        cc = char('A' + j);
                        break;
                    }
                }
   //             cout<<cc<<"\n";
                while(i <= jj)
                    s[i] = cc,  i += 2;
                i = jj;
            }
        }
    }
    cout<<ans<<"\n";
    cout<<s;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

