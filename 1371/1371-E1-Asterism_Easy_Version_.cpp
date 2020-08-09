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

const ll N = 100005;
ll a[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, p, mx = 0;
  cin >> n >> p;
  f(0, n) cin >> a[i], mx = max(mx, a[i]);
  sort(a, a + n);
  vll ans;
  ll current = 1;
  while (1) {
    if (current > mx)
      break;
    bool done = false, pos = true;
    ll c = current, minRem = 0, lat = 1e18;
    while (c < current + n) {
      ll k = upper_bound(a, a + n, c) - a;
      ll rem = c - current;
      rem = k - rem;
      if (rem <= 0) {
        ll x = upper_bound(a, a + n, c) - a;
        minRem = max(minRem, a[x] - c);
        pos = false;
      }
      if (k != n)
        lat = min(lat, a[k] - c);
      if (rem > 0 && rem % p == 0)
        done = true;
      c++;
    }
    if (pos && !done) {
      ans.pb(current);
      current += lat;
      if (lat == 0)
        current++;
    } else if (!pos) {
      current += minRem;
      if (minRem == 0)
        current++;
    } else {
      current += lat;
      if (lat == 0)
        current++;
    }
  }
  cout << ans.size() << '\n';
  f(0, ans.size()) cout << ans[i] << ' ';

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}