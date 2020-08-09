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
    vector<pair<ll, string>> pp;
    string s[2*n - 2];
    f(0, 2*n - 2)
    {
        cin>>s[i];
        pp.pb(mp(s[i].length(), s[i]));
    }
    if(n == 2)
    {
        cout<<"PS";
        return 0;
    }
    sort(pp.begin(), pp.end());
    string s1 = pp[0].second, s2 = pp[1].second, s3 = pp[2].second, s4 = pp[3].second;
    string p = "", p1 = "";
    if(s3 == s4)
    {
        if(s1[0] == s3[0])
        {
            p = s1;
            p1 = s3;
        }
        else
        {
            p = s2;
            p1 = s4;
        }
    }
    else if(s3[1] == s4[1])
    {
        if(s1[0] == s3[1])
        {
            p = s2;
            if(s3[0] == s2[0])
                p1 = s3;
            else p1 = s4;
        }
        else
        {
            p = s1;
            if(s3[0] == s1[0])
                p1 = s3;
            else p1 = s4;
        }
    }
    else
    {
        char c1 = s3[1],    c2 = s4[1];
        if(s3[0] == s4[0])
        {
            if(s1[0] == s3[0])
            {
                p = s1;
                char cc = s2[0];
                if(s3[1] != cc)
                    p1 = s3;
                else p1 = s4;
            }
            else
            {
                p = s2;
                char cc = s1[0];
                if(s3[1] != cc)
                    p1 = s3;
                else p1 = s4;
            }
        }
        else
        {
            char cc = s1[0];
            if(s3[0] == cc || s4[0] == cc)
            {
                p = s1;
                if(s3[0] == cc)
                    p1 = s3;
                else p1 = s4;
            }
            else
            {
                p = s2;
                cc = s2[0];
                if(s3[0] == cc)
                    p1 = s3;
                else p1 = s4;
            }
        }
    }
    char ss;
    if(p == s1)
        ss = s2[0];
    else ss = s1[0];
        map<string, ll> ans;
        ans[p]++;
        ans[p1]++;
        f(4, pp.size())
        {
            string z = pp[i].second, z1 = pp[i+1].second;
            if(z[0] == p1[0] && z[1] == p1[1] && z[z.length() - 1] != ss)
                ans[z]++;
            else if(z1[0] == p1[0] && z1[1] == p1[1] && z1[z1.length() - 1] != ss)
                ans[z1]++;
            else if(z[0] == p1[0] && z[1] == p1[1])
                ans[z]++;
            else if(z1[0] == p1[0] && z1[1] == p1[1])
                ans[z1]++;
            i++;
        }
    //    cout<<p<<" "<<p1<<"\n";
        f(0, 2*n - 2)
        {
            if(ans[s[i]] != 0)
            {
                cout<<"P";
                ans[s[i]]--;
            }
            else cout<<"S";
        }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

