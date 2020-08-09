#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

ll blockSize, mn[300050], mx[300050], a[300050], c, moLeft, moRight, fr[300050], n, m, x;
bool b[300050];
vll v[300050];
vector<pair<pair<ll, ll>, ll>> query;

bool compare(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
    if (a.first.first / blockSize == b.first.first / blockSize)
    {
        if ((a.first.first / blockSize) & 1)
            return a.first.second < b.first.second;
        return a.first.second > b.first.second;
    }
    return a.first.first / blockSize < b.first.first / blockSize;
}

void add(ll k)
{
    if (fr[k] == 0)
        c++;
    fr[k]++;
}

void remove(ll k)
{
    if (fr[k] == 1)
        c--;
    fr[k]--;
}

void update(ll l, ll r, ll in)
{
    while (moLeft < l)
        remove(a[moLeft++]);
    while (moLeft > l)
        add(a[--moLeft]);
    while (moRight < r)
        add(a[++moRight]);
    while (moRight > r)
        remove(a[moRight--]);
    mx[in] = max(mx[in], c);
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
    blockSize = sqrt(n);
    f(1, m + 1) cin >> a[i], v[a[i]].pb(i);
    ordered_set s;
    f(1, m + 1)
    {
        if (b[a[i]])
            continue;
        mn[a[i]] = 1;
        mx[a[i]] = a[i] + (ll)s.size() - s.order_of_key(a[i]);
        s.insert(a[i]);
        b[a[i]] = true;
    }
    f(1, n + 1) if (!b[i]) mn[i] = i, mx[i] = mn[i] + (ll)s.size() - s.order_of_key(i);
    f(1, n + 1) if (b[i]) v[i].pb(m + 1);
    f(1, n + 1) if (v[i].size() > 0) fi(0, v[i].size() - 1) query.pb({{v[i][j], v[i][j + 1]}, i});
    sort(query.begin(), query.end(), compare);
    moLeft = 0;
    moRight = 0;
    f(0, query.size())
        update(query[i].first.first, query[i].first.second, query[i].second);
    f(1, n + 1) cout << mn[i] << " " << mx[i] << "\n";

#ifndef ONLINE_JUDGE
    cout
        << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}