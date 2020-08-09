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

set<ll> r[1000005], c[1000005];
vector<pair<ll, pair<ll, ll>>> p;
ll n, m, rt[1000050], maxx[1000050];

void init()
{
    f(0, 1000050) rt[i] = i;
}

ll root(ll i)
{
    while (rt[i] != i)
        i = rt[rt[rt[rt[i]]]];
    return i;
}

void unionn(ll x, ll y)
{
    ll xr = root(x), yr = root(y);
    if (xr == yr)
        return;
    maxx[xr] = max(maxx[xr], maxx[yr]);
    rt[yr] = xr;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    init();
    ll a[n][m];
    f(0, n) fi(0, m) cin >> a[i][j], r[i].insert(a[i][j]), c[j].insert(a[i][j]), p.pb({a[i][j], {i, j}});
    sort(p.begin(), p.end());
    f(0, p.size())
    {
        ll x = p[i].first, j = i;
        pll p1, p2;
        while (j < p.size() && p[j].first == x)
        {
            ll mx = 0;
            auto k = r[p[j].second.first].lower_bound(x);
            if (k != r[p[j].second.first].begin())
                k--, mx = max(mx, *k + 1);
            k = c[p[j].second.second].lower_bound(x);
            if (k != c[p[j].second.second].begin())
                k--, mx = max(mx, *k + 1);
            maxx[p[j].second.first * m + p[j].second.second] = mx;
            p1.pb({p[j].second.first, p[j].second.second});
            p2.pb({p[j].second.second, p[j].second.first});
            j++;
        }
        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());
        fii(0, p1.size()) if (k != 0 && p1[k - 1].first == p1[k].first)
            unionn(p1[k].first * m + p1[k - 1].second, p1[k].first * m + p1[k].second);
        fii(0, p2.size()) if (k != 0 && p2[k - 1].first == p2[k].first)
            unionn(p2[k - 1].second * m + p2[k - 1].first, p2[k].second * m + p2[k].first);
        fii(i, j)
        {
            if (r[p[k].second.first].find(x) != r[p[k].second.first].end())
                r[p[k].second.first].erase(x);
            if (c[p[k].second.second].find(x) != c[p[k].second.second].end())
                c[p[k].second.second].erase(x);
            r[p[k].second.first].insert(maxx[root(p[k].second.first * m + p[k].second.second)]);
            c[p[k].second.second].insert(maxx[root(p[k].second.first * m + p[k].second.second)]);
        }
        i = j - 1;
    }
    f(0, n)
    {
        fi(0, m) cout << maxx[root(i * m + j)] + 1 << " ";
        cout << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}