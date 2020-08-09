/*
    * AUTHOR : Divyanshu *
*/

#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll p[300050];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll a[n + 1];
    f(1, n + 1) cin >> a[i], p[a[i]] = i;
    pll ans;
    ll p1 = 1, p2 = n / 2 + 1;
    while(p1 != n/2 + 1 && p2 != n + 1)
    {
        if(a[p1] == p1 && a[p2] == p2)
        {
            p1++;
            p2++;
            continue;
        }
        // cout<<p1<<" "<<p2<<" "<<p[p1]<<" "<<p[p2]<<"\n";
        if(p[p2] == p2)
        {
            if(p[p1] == p1)
            {
                p1++;
                p2++;
                continue;
            }
            if(p[p1] < p2)
            {
                ans.pb({p[p1], n});
                ll k1 = a[n];
                p[k1] = p[p1];
                a[p[p1]] = k1;
                a[n] = p1;
                p[p1] = n;
            }
            else
            {
                ans.pb({p[p1], p1});
                ll k1 = a[p1];
                p[k1] = p[p1];
                a[p[p1]] = k1;
                a[p1] = p1;
                p[p1] = p1;
                p1++;
                p2++;
            }
        }
        else
        {
            if(p[p2] < p2 && p[p2] != p1)
            {
                ans.pb({p[p2], n});
                ll k1 = a[n];
                p[k1] = p[p2];
                a[p[p2]] = k1;
                a[n] = p2;
                p[p2] = n;
                if(a[p1] == p1 && a[p2] == p2)
                    continue;
                ans.pb({p[p2], p1});
                k1 = a[p1];
                p[k1] = p[p2];
                a[p[p2]] = k1;
                a[p1] = p2;
                p[p2] = p1;
            }
            else if(p[p2] != p1)
            {
                ans.pb({p[p2], p1});
                ll k1 = a[p1];
                p[k1] = p[p2];
                a[p[p2]] = k1;
                a[p1] = p2;
                p[p2] = p1;
            }
            if(a[p1] == p1 && a[p2] == p2)
                    continue;
            ans.pb({p1, p2});
            ll k1 = a[p2];
            p[k1] = p[p2];
            a[p[p2]] = k1;
            a[p2] = p2;
            p[p2] = p2;
        }
    }
    cout<<ans.size()<<"\n";
    f(0, ans.size())
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}