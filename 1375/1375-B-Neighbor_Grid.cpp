#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
/**      typedef tree<ll
 * ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 * ordered_set; */

template <class T> ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V)
    os << v << " ";
  os << "]";
  return os;
}
template <class T> ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S)
    os << s << " ";
  return os << "}";
}
template <class L, class R> ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M)
    os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R> ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}

const ll N = 305;
ll n, m, a[N][N];

bool safe(ll x, ll y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

ll count(ll x, ll y) {
  ll r = 0;
  if (safe(x - 1, y))
    r++;
  if (safe(x + 1, y))
    r++;
  if (safe(x, y - 1))
    r++;
  if (safe(x, y + 1))
    r++;
  return r;
}

bool check(ll x, ll y) { return count(x, y) >= a[x][y]; }

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    f(1, n + 1) fi(1, m + 1) cin >> a[i][j];
    bool pos = true;
    f(1, n + 1) fi(1, m + 1) pos &= check(i, j);
    if (!pos)
      cout << "NO\n";
    else {
      cout << "YES\n";
      f(1, n + 1) fi(1, m + 1) a[i][j] = count(i, j);
      f(1, n + 1) {
        fi(1, m + 1) cout << a[i][j] << ' ';
        cout << '\n';
      }
    }
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}