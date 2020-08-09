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
ll p[N], n, a, r, m;

ll calc(ll mid) {
  ll l = 0, h = 0;
  f(1, n + 1) {
    if (p[i] > mid)
      h += p[i] - mid;
    else if (p[i] < mid)
      l += mid - p[i];
  }
  if (l >= h)
    return min(a + r, m) * h + a * (l - h);
  return min(a + r, m) * l + r * (h - l);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> a >> r >> m;
  f(1, n + 1) cin >> p[i];
  ll l = 0, h = 1e9, ans = -1;
  while (l + 20 < h) {
    ll mid1 = (2 * l + h) / 3, mid2 = (l + 2 * h) / 3;
    ll m1 = calc(mid1), m2 = calc(mid2);
    if (m1 >= m2)
      ans = m2, l = mid1 + 1;
    else
      ans = m1, h = mid2 - 1;
  }
  f(l, h + 1) ans = min(ans, calc(i));
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}