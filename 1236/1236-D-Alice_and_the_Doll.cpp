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

ll n, moves, m, k, up, down, leftt, rightt, dir, tot; // 1 rightt  2 leftt  3 up  4 down
set<ll> row[100050], col[100050];
bool ok;

void movesrightt()
{
    if (row[up].find(leftt) != row[up].end())
    {
        ok = false;
        return;
    }
    if (row[up].empty())
    {
        moves += rightt - leftt + 1;
        up++;
        dir = 4;
        return;
    }
    ll k = *row[up].begin(), c = 0;
    f(k, rightt + 1)
    {
        while (!col[i].empty())
        {
            c++;
            ll x = *col[i].begin();
            row[x].erase(row[x].find(i));
            col[i].erase(col[i].begin());
        }
    }
    if (c != (rightt - k + 1) * (down - up + 1))
    {
        ok = false;
        return;
    }
    moves += k - leftt;
    up++;
    rightt = k - 1;
    tot += c;
    dir = 4;
}

void movesleftt()
{
    if (row[down].find(rightt) != row[down].end())
    {
        ok = false;
        return;
    }
    if (row[down].empty())
    {
        moves += rightt - leftt + 1;
        down--;
        dir = 3;
        return;
    }
    ll k = *row[down].rbegin(), c = 0;
    f(leftt, k + 1)
    {
        while (!col[i].empty())
        {
            c++;
            ll x = *col[i].begin();
            row[x].erase(row[x].find(i));
            col[i].erase(col[i].begin());
        }
    }
    if (c != (k - leftt + 1) * (down - up + 1))
    {
        ok = false;
        return;
    }
    moves += rightt - k;
    down--;
    leftt = k + 1;
    tot += c;
    dir = 3;
}

void movesUp()
{
    if (col[leftt].find(down) != col[leftt].end())
    {
        ok = false;
        return;
    }
    if (col[leftt].empty())
    {
        moves += down - up + 1;
        leftt++;
        dir = 1;
        return;
    }
    ll k = *col[leftt].rbegin(), c = 0;
    f(up, k + 1)
    {
        while (!row[i].empty())
        {
            c++;
            ll x = *row[i].begin();
            col[x].erase(col[x].find(i));
            row[i].erase(row[i].begin());
        }
    }
    if (c != (k - up + 1) * (rightt - leftt + 1))
    {
        ok = false;
        return;
    }
    moves += down - k;
    leftt++;
    up = k + 1;
    tot += c;
    dir = 1;
}

void movesDown()
{
    if (col[rightt].find(up) != col[rightt].end())
    {
        ok = false;
        return;
    }
    if (col[rightt].empty())
    {
        moves += down - up + 1;
        rightt--;
        dir = 2;
        return;
    }
    ll k = *col[rightt].begin(), c = 0;
    f(k, down + 1)
    {
        while (!row[i].empty())
        {
            c++;
            ll x = *row[i].begin();
            col[x].erase(col[x].find(i));
            row[i].erase(row[i].begin());
        }
    }
    if (c != (down - k + 1) * (rightt - leftt + 1))
    {
        ok = false;
        return;
    }
    moves += k - up;
    rightt--;
    down = k - 1;
    tot += c;
    dir = 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y;
    ok = true;
    cin >> n >> m >> k;
    if (k == 0)
    {
        cout << "Yes";
        return 0;
    }
    dir = 1;
    leftt = 1, rightt = m, up = 1, down = n;
    f(0, k) cin >> x >> y, row[x].insert(y), col[y].insert(x);
    while (ok && moves != (n * m) - k)
    {
        // cout << dir << " " << leftt << " " << rightt << " " << up << " " << down << " " << moves << " " <<tot<<" "
        //      << "\n";
        if (dir == 1)
            movesrightt();
        else if (dir == 2)
            movesleftt();
        else if (dir == 3)
            movesUp();
        else
            movesDown();
        // cout << dir << " " << leftt << " " << rightt << " " << up << " " << down << " " << moves << " "<<tot<<" "
        //      << "\n\n";
    }
    if (moves == (n * m) - k)
        cout << "Yes";
    else
        cout << "No";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}