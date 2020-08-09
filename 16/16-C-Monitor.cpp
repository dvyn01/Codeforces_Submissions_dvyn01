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

    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll g = __gcd(x, y);
    x /= g, y /= g;
    ll k1 = a / x * x, k2 = k1 * y / x;
    ll k4 = b / y * y, k3 = x * k4 / y;
    ll a1 = 0, a2 = 0;
    a1 = k1 * k2;
    a2 = k3 * k4;
    bool done = false;
    if (a1 == 0 && a2 == 0)
        done = true, cout << "0 0";
    if (!done && a1 >= a2)
    {
        if (k1 <= a && k2 <= b)
            done = true, cout << k1 << " " << k2 << "\n";
        else if (k3 <= a && k4 <= b)
            done = true, cout << k3 << " " << k4 << " ";
    }
    else if (!done && a2 > a1)
    {
        if (k3 <= a && k4 <= b)
            done = true, cout << k3 << " " << k4 << " ";
        else if (k1 <= a && k2 <= b)
            done = true, cout << k1 << " " << k2 << "\n";
    }
    if (!done)
        cout << "0 0";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}