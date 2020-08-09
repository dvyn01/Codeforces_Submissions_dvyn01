#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define pb push_back
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

const ll N = 100005;
ll ans[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, p, x;
    cin >> n >> p;
    set<pair<ll, ll>> s;
    set<ll> wait, qs;
    queue<ll> q;
    f(1, n + 1) cin >> x, s.insert({x, i});
    ll done = 0, ct = 0;
    while (done < n)
    {
        if (q.empty())
            q.push(s.begin()->second), qs.insert(s.begin()->second), ct = s.begin()->first, s.erase(s.begin());
        ct += p;
        ans[q.front()] = ct;
        ll ci = q.front();
        qs.erase(qs.find(q.front()));
        q.pop();
        done++;
        // if(q.empty() && !wait.empty())
        //     q.push(*wait.begin()), qs.insert(*wait.begin()), wait.erase(wait.begin());
        while (!s.empty() && s.begin()->first <= ct)
        {
            if (qs.empty() && wait.empty() && s.begin()->second < ci)
                qs.insert(s.begin()->second), q.push(s.begin()->second);
            else if (!qs.empty() && wait.empty() && *qs.begin() > s.begin()->second && s.begin()->second < ci)
                qs.insert(s.begin()->second), q.push(s.begin()->second);
            else if (!wait.empty() && qs.empty() && *wait.begin() > s.begin()->second && s.begin()->second < ci)
                qs.insert(s.begin()->second), q.push(s.begin()->second);
            else if (!qs.empty() && !wait.empty() && s.begin()->second < *qs.begin() && s.begin()->second < *wait.begin() && s.begin()->second < ci)
                qs.insert(s.begin()->second), q.push(s.begin()->second);
            else
                wait.insert(s.begin()->second);
            s.erase(s.begin());
            // cout << qs << ' ' << wait << '\n';
        }
        if (qs.empty() && !wait.empty())
            qs.insert(*wait.begin()), q.push(*wait.begin()), wait.erase(wait.begin());
        // cout << s << ' ' << qs << ' ' << wait << "\n\n";
    }
    f(1, n + 1) cout << ans[i] << ' ';

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}