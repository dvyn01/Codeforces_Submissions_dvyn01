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

    ll l;
    cin >> l;
    ll x = 0;
    bool over = false;
    stack<pair<ll, ll>> ss;
    stack<pair<ll, ll>> s1;
    while (l--)
    {
        string s;
        cin >> s;
        if(over)
            continue;
        if (s == "for")
        {
            ll xx;
            cin >> xx;
            ss.push({xx, l});
            if (xx > 1)
                s1.push({xx, l});
        }
        else if (s == "add")
        {
            ll k = 1;
            stack<pl> s2;
            while (!s1.empty())
            {
                k *= s1.top().first;
                s2.push(s1.top());
                s1.pop();
                if (k + x > ((1LL << 32) - 1))
                {
                    over = true;
                }
            }
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            x += k;
            if (x > ((1LL << 32) - 1))
            {
                over = true;
            }
        }
        else
        {
            if (!s1.empty() && ss.top().second == s1.top().second)
                s1.pop();
            ss.pop();
            // cout<<ss.size()<<" "<<s1.size()<<"\n";
        }
        // cout << l << " " << c << " " << x << "\n";
    }
    if (x > ((1LL << 32) - 1))
    {
        over = true;
    }
    if (over)
        cout << "OVERFLOW!!!";
    else
        cout << x;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}