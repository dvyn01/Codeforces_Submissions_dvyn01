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

    ll n, x, ts = 0,  d = 0;
    cin>>n;
    pll t;
    vll v;
    f(0, n)
    {
        cin>>x;
        if(x >= 2)
        {   t.pb(mp(x, i+1));   ts += x;    }
        else v.pb(i+1);
    }
    if(t.size() == 0)
    {
        cout<<"NO";
        return 0;
    }
    if(t.size() > 1 && (ts - (t.size()-2) * 2 - 2) < v.size())
    {
        cout<<"NO";
        return 0;
    }
    if(t.size() == 1 && ts < v.size())
    {
        cout<<"NO";
        return 0;
    }
    sort(t.begin(), t.end());
    pll ans;
    if(t.size() == 1)
    {
        f(0, v.size())      ans.pb(mp(t[0].second, v[i]));
        if(v.size() == 1)   d = 1;
        else if(v.size() > 1)   d = 2;
        cout<<"YES "<<d<<"\n"<<ans.size()<<"\n";
        f(0, ans.size())        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        return 0;
    }
    ll fc = t[t.size() - 1].second, sc = t[t.size() - 2].second, lv = -1;
    bool done = false;
    if(t.size() == 3)
    {
        ans.pb(mp(fc, t[0].second));
        ans.pb(mp(t[0].second, sc));
        t[0].first -= 2;
        t[1].first--;
        t[2].first--;
        ts -= 4;
    }
    else if(t.size() == 2)
    {
        ans.pb(mp(fc, sc));
        t[0].first--;
        t[1].first--;
        ts -= 2;
    }
    else{
        f(0, t.size() - 2)
        {
            done = true;
            if(i == 0)
            {
                ans.pb(mp(fc, t[i].second));
                t[i].first--;
                t[t.size() - 1].first--;
                ts -= 2;
                lv = t[i].second;
            }
            else if(i == t.size() - 3)
            {
                ans.pb(mp(t[i].second, lv));
                ans.pb(mp(sc, t[i].second));
                t[i].first -= 2;
                t[i-1].first--;
                t[t.size() - 2].first--;
                ts -= 2;
            }
            else
            {
                ans.pb(mp(t[i].second, lv));
                t[i].first--;
                t[i-1].first--;
                lv = t[i].second;
                ts -= 2;
            }
        }
    }
    if(v.size() <= 1)
    {
        if(v.size() == 1)
            ans.pb(mp(t[t.size() - 1].second, v[0]));
        goto anss;
    }
    if(t.size() == 1)
        f(0, v.size())      ans.pb(mp(v[i], t[0].first));
    else{
        ans.pb(mp(v[0], t[t.size() - 1].second));       t[t.size() - 1].first--;
        ans.pb(mp(v[1], t[t.size() - 2].second));       t[t.size() - 2].first--;
        sort(t.begin(), t.end());
        reverse(t.begin(), t.end());
        ll cp = 0;
        if(v.size() >= 3)
        {
            f(2, v.size())
            {
                while(cp != t.size() && t[cp].first == 0)
                    cp++;
                ans.pb(mp(v[i], t[cp].second));
                t[cp].first--;
            }
        }
    }
    anss:
    if(v.size() == 0)
        d = t.size() - 1;
    else if(v.size() == 1)  d = t.size();
    else {  d = t.size() + 1;   }
    cout<<"YES"<<" "<<d<<"\n"<<ans.size()<<"\n";
    f(0, ans.size())
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

