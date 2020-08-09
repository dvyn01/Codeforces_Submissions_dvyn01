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

inline ll mul(ll x, ll y, ll m)
{
    ll z = 1LL * x * y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll add(ll x, ll y, ll m)
{
    ll z = x + y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll sub(ll x, ll y, ll m)
{
    ll z = x - y;
    if (z < 0)
        z += m;
    z %= m;
    return z;
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
    // bool ok = true;
    pll p;
    f(0, m)
    {
        ll x, y;
        cin >> x >> y;
        p.pb({x, y});
    }
    if (m == 2)
    {
        cout << "YES";
        return 0;
    }
    sort(p.begin(), p.end());
    map<ll, ll> m1;
    // bool ok = false;
    // ll x = p[p.size() - 1].first;
    // ll k = p.size() - 2;
    // while(k >= 0 && p[k].first == x)
    //     k--;
    // if(k == -1)
    // {
    //     cout<<"YES";
    //     return 0;
    // }
    // map<ll, ll> m1;
    // ll c = 0;
    // fr(k, 0)
    // {
    //     if(p[j].second == x || p[j].first == x)
    //     {
    //         c++;
    //         continue;
    //     }
    //     m1[p[j].first]++,    m1[p[j].second]++;
    // }
    // for(auto it = m1.begin(); it != m1.end(); it++)
    // {
    //     if(it -> second >= k - c + 1)
    //     {
    //         cout<<"YES";
    //         return 0;
    //     }
    // }
    // m1.clear();
    // pll p1;
    // f(0, p.size())
    //     p1.pb({p[i].second, p[i].first});
    // sort(p1.begin(), p1.end());
    // x = p1[p1.size() - 1].first;
    // k = p1.size() - 2;
    // while(k >= 0 && p1[k].first == x)
    //     k--;
    // if(k == -1)
    // {
    //     cout<<"YES";
    //     return 0;
    // }
    // c = 0;
    // fr(k, 0)
    // {
    //     if(p1[j].second == x)
    //     {
    //         c++;
    //         continue;
    //     }
    //     m1[p1[j].first]++,    m1[p1[j].second]++;
    // }
    // for(auto it = m1.begin(); it != m1.end(); it++)
    // {
    //     if(it -> second >= k - c + 1)
    //     {
    //         cout<<"YES";
    //         return 0;
    //     }
    // }
    m1.clear();
    ll c = 0;
    ll x = p[p.size() - 1].first;
    f(0, p.size())
    {
        if (p[i].first == x || p[i].second == x)
        {
            c++;
            continue;
        }
        m1[p[i].first]++;
        m1[p[i].second]++;
    }
    if (c == m)
    {
        cout << "YES";
        return 0;
    }
    for (auto it = m1.begin(); it != m1.end(); it++)
    {
        if (it->second + c >= m)
        {
            cout << "YES";
            return 0;
        }
    }
    m1.clear();
    c = 0;
    x = p[p.size() - 1].second;
    f(0, p.size())
    {
        if (p[i].first == x || p[i].second == x)
        {
            c++;
            continue;
        }
        m1[p[i].first]++;
        m1[p[i].second]++;
    }
    if (c == m)
    {
        cout << "YES";
        return 0;
    }
    for (auto it = m1.begin(); it != m1.end(); it++)
    {
        if (it->second + c >= m)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}