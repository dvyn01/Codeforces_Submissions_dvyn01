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
    string s;
    cin >> s;
    ll c = 0;
    f(0, s.length()) if (s[i] == '?') c++;
    if (c < 2)
    {
        if (c == 0)
        {
            ll s1 = 0, s2 = 0;
            f(0, n / 2) s1 += s[i] - '0';
            f(n / 2, n) s2 += s[i] - '0';
            if (s1 == s2)
                cout << "Bicarp";
            else
                cout << "Monocarp";
            return 0;
        }
        else
        {
            cout << "Monocarp";
            return 0;
        }
    }
    ll s1 = 0, s2 = 0, c1 = 0, c2 = 0;
    f(0, n / 2)
    {
        if (s[i] != '?')
            s1 += s[i] - '0';
        else
            c1++;
    }
    f(n / 2, n)
    {
        if (s[i] != '?')
            s2 += s[i] - '0';
        else
            c2++;
    }
    ll add = 0, sub = 0, diff = abs(s1 - s2);
    if (s1 >= s2)
    {
        if (c1 >= c2)
            add += c1 - c2;
        else
            sub += c2 - c1;
    }
    else
    {
        if (c2 >= c1)
            add += c2 - c1;
        else
            sub += c1 - c2;
    }
    // cout << c1 << " " << c2 << " " << add << " " << sub << " " << diff << "\n";
    if (add > 0 && diff > 0)
    {
        cout << "Monocarp";
        return 0;
    }
    if (diff == 0)
    {
        if (add != sub)
            cout << "Monocarp";
        else
            cout << "Bicarp";
        return 0;
    }
    ll x = sub / 2;
    if (sub & 1)
        x++;
    if (x * 9 > diff)
    {
        cout << "Monocarp";
        return 0;
    }
    if (sub & 1)
        x--;
    if (x * 9 < diff)
    {
        cout << "Monocarp";
        return 0;
    }
    cout << "Bicarp";
    // cout<<s1<<" "<<s2<<"\n";
    // if (s1 == s2)
    //     cout << "Bicarp";
    // else
    //     cout << "Monocarp";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}