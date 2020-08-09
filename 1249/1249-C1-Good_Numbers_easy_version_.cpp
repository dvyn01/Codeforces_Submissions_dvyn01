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
    ll xxx[45];
    xxx[0] = 1;
    f(1, 40) xxx[i] = xxx[i - 1] * 3;
    while (t--)
    {
        ll n;
        cin >> n;
        ll x = 0, y = n, mx = -1, c = 0, mn = -1, mnn = -1;
        map<ll, ll> m;
        fr(40, 0)
        {
            if (pow(3, j) <= y)
            {
                if (mx == -1)
                    mx = j;
                c++;
                m[j] = 1;
                ll p = xxx[j];
                y -= p;
                x += p;
                mnn = j;
            }
            else
                mn = j;
        }
        // cout << x << " " << y << " " << mx << " " << mn << " " << c << "\n";
        if (y == 0)
        {
            cout << x << "\n";
            continue;
        }
        if (mx + 1 == c)
            x = xxx[mx + 1];
        else
        {
            f(0, 40)
            {
                if(m[i] == 0) 
                {
                    x += xxx[i];
                    break;
                }
                x -= xxx[i];
            }
        }
        cout << x << "\n";
    }

    return 0;
}