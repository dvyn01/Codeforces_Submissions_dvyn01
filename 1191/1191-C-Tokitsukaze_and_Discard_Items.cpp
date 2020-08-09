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

    ll n, m, k;
    cin >> n >> m >> k;
    ll a[m];
    set<pair<ll, ll>> s;
    f(0, m) cin >> a[i], s.insert({(a[i] - 1) / k, a[i] - 1});
    if (m == 0)
    {
        cout << 0;
        return 0;
    }
    ll c = 0, p = s.begin()->first, ans = 0;
    while (!s.empty())
    {
        pll wow;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if ((it->second - c) / k != p)
                break;
            wow.pb({it->first, it->second});
        }
        f(0, wow.size())
            s.erase(s.find({wow[i].first, wow[i].second})),
            c++;
        if (!s.empty())
            p = (s.begin()->second - c) / k;
        ans++;
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}