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

ll n, x, a[500050], l;

void rec(ll start, ll end, ll mx)
{
    // cout<<start<<" "<<end<<" "<<mx<<"\n";
    if(start == end)
    {
        if(a[start] == 0)
        a[start] = 1;
        return;
    }
    ll mid = start + end >> 1;
    a[mid] = mx;
    // cout<<mid<<" "<<a[mid]<<"\n";
    rec(start, mid, mx / 2);
    rec(mid + 1, end, mx / 2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    if (n == 1)
    {
        if (x == 1)
            cout << 0;
        else
        {
            cout << 1 << "\n";
            cout << 1;
        }
        return 0;
    }
    if(x >= (1LL << n))
        l = (1LL << n) - 1;
    else l = (1LL << (n-1)) - 1;
    rec(1, l, (l + 1) / 2);
    ll lb = 0, up = 1;
    while(up <= 18)
    {
        if(x >= (1LL << lb) && x < (1LL << up))
            break;
        lb++; up++;
    }
    f(1, l + 1)
    {
        if(a[i] >= (1LL << lb))
            a[i] *= 2;
    }
    cout<<l<<"\n";
    f(1, l+1)
    {
        cout<<a[i]<<" ";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}