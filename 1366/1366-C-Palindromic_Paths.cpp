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
//      typedef tree<ll
//      ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//      ordered_set;

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

const ll N = 100005;

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
    ll n, m;
    cin >> n >> m;
    ll a[n][m];
    f(0, n) fi(0, m) cin >> a[i][j];
    ll ans = 0;
    ll lux = -1, luy = -1, ldx = -1, ldy = -1;
    while (1) {
      ll c0 = 0, c1 = 0, ux, uy, dx, dy;
      if (lux == -1)
        ux = 0, uy = 0, dx = n - 1, dy = m - 1;
      else {
        if (luy == m - 1)
          ux = lux + 1, uy = luy;
        else
          ux = lux, uy = luy + 1;
        if (ldx == 0)
          dx = ldx, dy = ldy - 1;
        else
          dx = ldx - 1, dy = ldy;
      }
      lux = ux, luy = uy, ldx = dx, ldy = dy;
      if (ux > dx || dy < uy)
        break;
      if (lux == ldx && luy == ldy)
        break;
      while (ux < n && uy >= 0)
        (a[ux++][uy--] == 1) ? c1++ : c0++;
      while (dx < n && dy >= 0)
        (a[dx++][dy--] == 1) ? c1++ : c0++;
      ans += min(c0, c1);
    }
    cout << ans << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}