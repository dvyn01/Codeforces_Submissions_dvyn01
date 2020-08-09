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
        ll a[n];
        f(0, n) cin >> a[i];
        if(k == 1)
        {
            ll s = 0;
            f(0, n)
                s += a[i];
            if(!(s & 1))
                cout<<"NO\n";
            else cout<<"YES\n"<<n<<"\n";
            continue;
        }
        ll s = 0;
        vll v;
        f(0, n)
        {
            s += a[i];
            if (s & 1)
            {
                v.pb(i + 1);
                s = 0;
            }
            if (v.size() == k - 1)
                break;
        }
        if(v.size() < k - 1)
        {
            cout<<"NO\n";
            continue;
        }
        f(v[v.size() - 1], n)
            s += a[i];
        if (!(s & 1) || (v.size() < k - 1) || (v.size() == k - 1 && v[v.size() - 1] == n))
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            f(0, v.size()) cout << v[i] << " ";
            cout << n << "\n";
        }
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}