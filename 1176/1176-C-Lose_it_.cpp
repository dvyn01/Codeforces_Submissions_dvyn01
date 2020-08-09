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

    ll n;
    cin >> n;
    set<ll> v[6];
    ll a[n];
    f(0, n)
    {
        cin >> a[i];
        if (a[i] == 4)
            v[0].insert(i);
        else if (a[i] == 8)
            v[1].insert(i);
        else if (a[i] == 15)
            v[2].insert(i);
        else if (a[i] == 16)
            v[3].insert(i);
        else if (a[i] == 23)
            v[4].insert(i);
        else if (a[i] == 42)
            v[5].insert(i);
    }
    ll ans = 0;
    for (auto it = v[0].begin(); it != v[0].end(); it++)
    {
        ll k = *it;
        ll in = 1;
        while (in < 6)
        {
            auto k1 = v[in].lower_bound(k);
            if (k1 == v[in].end())
                break;
            k = *k1;
            v[in].erase(k1);
            in++;
        }
        if (in == 6)
            ans += 6;
        else
            break;
    }
    ans = n - ans;
    cout<<ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}