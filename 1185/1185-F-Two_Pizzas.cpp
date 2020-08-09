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

ll person[600];
set<pair<ll, ll>> pizza[600];
pair<ll, pair<ll, ll>> combo[600];

ll calculate(ll x)
{
    ll r = 0;
    f(1, 512) if ((i & x) == i)
        r += person[i];
    return r;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    f(0, n)
    {
        ll x, y, r = 0;
        cin >> x;
        while (x--)
            cin >> y, r |= (1LL << (y - 1));
        person[r]++;
    }
    f(0, m)
    {
        ll c, x, y, r = 0;
        cin >> c >> x;
        while (x--)
            cin >> y, r |= (1LL << (y - 1));
        pizza[r].insert({c, i + 1});
        if (pizza[r].size() > 2)
            pizza[r].erase(--pizza[r].end());
    }
    f(0, 600) combo[i].first = 1e18;
    f(0, 512)
    {
        fi(i, 512)
        {
            if (i == j)
            {
                if (pizza[i].size() < 2)
                    continue;
                auto it = pizza[i].begin();
                auto it1 = (++pizza[i].begin());
                if (it->first + it1->first < combo[i].first)
                    combo[i].first = it->first + it1->first, combo[i].second.first = it->second, combo[i].second.second = it1->second;
            }
            else
            {
                if (pizza[i].size() == 0 || pizza[j].size() == 0)
                    continue;
                auto it = pizza[i].begin();
                auto it1 = pizza[j].begin();
                if (it->first + it1->first < combo[i | j].first)
                    combo[i | j].first = it->first + it1->first, combo[i | j].second.first = it->second, combo[i | j].second.second = it1->second;
            }
        }
    }
    ll mc = 1e18, mx = 0, in1 = -1, in2 = -1;
    f(0, 512)
    {
        if (combo[i].first == 1e18)
            continue;
        ll persons = calculate(i);
        if (persons > mx)
            mx = persons, mc = combo[i].first, in1 = combo[i].second.first, in2 = combo[i].second.second;
        else if (persons == mx)
        {
            if (combo[i].first < mc)
                mc = combo[i].first, in1 = combo[i].second.first, in2 = combo[i].second.second;
        }
    }
    cout << in1 << " " << in2;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}