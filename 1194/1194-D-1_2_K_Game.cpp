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
        ll n, k;
        cin >> n >> k;
        if (k == 0)
        {
            cout << "Bob\n";
            continue;
        }
        if (k > n)
        {
            if (n % 3 == 0)
                cout << "Bob\n";
            else
                cout << "Alice\n";
            continue;
        }
        if (k == n)
        {
            cout << "Alice\n";
            continue;
        }
        if (k % 3 == 0)
        {
            ll x = k / 3;
            n -= k;
            ll y = x * 3 + 1;
            n %= y;
            if (n % 3 == 1)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
        else
        {
            if (n % 3 == 0)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}