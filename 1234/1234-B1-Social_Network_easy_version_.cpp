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
#define print(x) cerr << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    ll a[n];
    f(0, n) cin >> a[i];
    map<ll, ll> m;
    ll c = 0;
    queue<ll> q;
    f(0, n)
    {
        if (c < k)
        {
            if (m.find(a[i]) != m.end())
                continue;
            q.push(a[i]);
            c++;
            m[a[i]] = 1;
            continue;
        }
        if (m.find(a[i]) != m.end())
            continue;
        ll x = q.front();
        q.pop();
        m.erase(m.find(x));
        m[a[i]] = 1;
        q.push(a[i]);
    }
    cout << q.size() << "\n";
    vll v;
    while (!q.empty())
        v.pb(q.front()), q.pop();
    fr(v.size() - 1, 0) cout << v[j] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}