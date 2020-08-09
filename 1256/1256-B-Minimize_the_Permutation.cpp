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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        map<ll, ll> m;
        f(0, n) cin >> a[i], m[a[i]] = i;
        ll rp = 0;
        f(1, n + 1)
        {
            if (m[i] < rp)
                continue;
            if (m[i] == rp)
            {
                rp++;
                continue;
            }
            ll y = m[i];
            while (m[i] > rp)
            {
                ll k = m[i] - 1;
                swap(a[k], a[k + 1]);
                m[a[k + 1]] = k + 1;
                m[a[k]] = k;
            }
            rp = y;
        }
        f(0, n) cout << a[i] << " ";
        cout << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}