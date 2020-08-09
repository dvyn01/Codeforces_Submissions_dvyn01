/*
    * AUTHOR : Divyanshu *
*/

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
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

string r, x;

void Z(string s, ll z[])
{
    ll l = 0, r = 0;
    f(1, s.length())
    {
        if (i > r)
        {
            l = r = i;
            while (r < s.length() && s[r - l] == s[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            ll k = i - l;
            if (z[k] < r - i + 1)
                z[i] = z[k];
            else
            {
                l = i;
                while (r < s.length() && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}

bool find()
{
    if (x.length() == 1 || x.length() > r.length())
        return false;
    ll a[105000], b[105000];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    string s = x + '$' + r;
    Z(s, a);
    reverse(x.begin(), x.end());
    reverse(r.begin(), r.end());
    s = x + '$' + r;
    Z(s, b);
    reverse(r.begin(), r.end());
    reverse(x.begin(), x.end());
    f(x.length() + 1, s.length())
    {
        b[i] = max(b[i], b[i - 1]);
        if (b[i] >= x.length())
            return true;
    }
    f(0, r.length() + 1) a[i] = a[i + x.length()], b[i] = b[i + x.length()];
    f(1, r.length() + 1)
    {
        if (a[i] >= x.length())
            return true;
        ll k = i + a[i] - 1;
        k = r.length() - k;
        k -= x.length() - a[i] - 1;
        if (k >= 0 && a[i] + b[k] >= x.length())
            return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r;
    ll m, ans = 0;
    cin >> m;
    f(1, m + 1) cin >> x, (find()) ? ans++ : 0;
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}