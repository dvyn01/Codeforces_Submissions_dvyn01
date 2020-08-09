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

template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    os << "[ ";
    for (auto v : V)
        os << v << " ";
    os << "]";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S)
{
    os << "{ ";
    for (auto s : S)
        os << s << " ";
    return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M)
{
    os << "{ ";
    for (auto m : M)
        os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}

ll n, m, a[100050], d[100050];
pll need;
vector<pair<ll, pair<ll, ll>>> ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y, w;
    cin >> n >> m;
    f(0, m) cin >> x >> y >> w, d[x] += w, a[y] += w;
    // f(1, n+1) cout<<d[i]<<" "<<a[i]<<"\n";
    f(1, n + 1) need.pb({d[i] - a[i], i});
    sort(need.begin(), need.end());
    ll lp = 0, rp = n - 1;
    // cout << need << "\n";
    while (lp < rp)
    {
        ll val = min(abs(need[lp].first), abs(need[rp].first));
        if (val == 0)
        {
            if (val == need[lp].first)
                lp++;
            else
                rp--;
            continue;
        }
        if (val == abs(need[lp].first))
        {
            ans.pb({val, {need[lp].second, need[rp].second}});
            need[rp].first -= val;
            lp++;
        }
        else
        {
            ans.pb({val, {need[lp].second, need[rp].second}});
            need[lp].first += val;
            rp--;
        }
    }
    cout << ans.size() << "\n";
    f(0, ans.size()) cout << ans[i].second.second << " " << ans[i].second.first << " " << ans[i].first << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}