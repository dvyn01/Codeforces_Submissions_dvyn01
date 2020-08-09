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
    f(0, n) cin >> a[i];
    ll b[n];
    memset(b, 0, sizeof(b));
    if (a[0] < 0)
        b[0] = 1;
    else
        b[0] = 0;
    f(1, n)
    {
        b[i] = b[i - 1];
        if (a[i] < 0)
            b[i] ^= 1;
    }
    // f(0, n) cout << b[i] << " ";
    // cout << "\n";
    ll oc = 0, zc = 0;
    f(0, n)
    {
        if (b[i] == 1)
            oc++;
        else
            zc++;
    }
    ll ne = 0, po = 0;
    ne += oc;
    po += zc;
    if(b[0] == 0)
        zc--;
    else oc--;
    f(1, n)
    {
        if (b[i - 1] == 0)
        {
            ne += oc;
            po += zc;
        }
        else
        {
            ne += zc;
            po += oc;
        }
        if (b[i] == 1)
            oc--;
        else
            zc--;
    }
    cout << ne << " " << po;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}