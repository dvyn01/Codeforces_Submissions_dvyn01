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
    ll a[n];
    map<ll, ll> mm, m1;
    f(0, n) cin >> a[i], mm[a[i]]++, m1[a[i]]++;
    for (auto it = mm.begin(); it != mm.end(); it++)
    {
        if (it->second > 1 && m1[it->first - 1] > 0)
        {
            cout << "cslnb\n";
            return 0;
        }
    }
    sort(a, a + n);
    ll moves = 0, mx = 0;
    ll xx = 0;
    f(0, n)
    {
        ll j = i, c = 0;
        while (j < n && a[j] == a[i])
            j++, c++;
        i = j - 1;
        if (c > 2)
        {
            cout << "cslnb\n";
            return 0;
        }
        if (c == 2)
            xx++;
    }
    if (xx > 1)
    {
        cout << "cslnb\n";
        return 0;
    }
    f(0, n)
    {
        ll x = max(a[i] - i, max(0LL, a[i] - mx - 1));
        moves += x;
        a[i] -= x;
        mx = a[i];
    }
    // cout << moves << "\n";
    f(0, n)
    {
        ll j = i, c = 0;
        while (j < n && a[j] == a[i])
            j++, c++;
        i = j - 1;
        if (c > 1)
        {
            cout << "cslnb\n";
            return 0;
        }
    }
    if (moves & 1)
        cout << "sjfnb";
    else
        cout << "cslnb";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}