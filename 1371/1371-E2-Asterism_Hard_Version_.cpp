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
ll a[N], n, p;

bool pos(ll current) {
  ll c = current;
  while (c < current + n) {
    ll k = upper_bound(a, a + n, c) - a;
    ll rem = c - current;
    rem = k - rem;
    if (rem <= 0)
      return false;
    c++;
  }
  return true;
}

bool check(ll current) {
  ll c = current;
  while (c < current + n) {
    ll k = upper_bound(a, a + n, c) - a;
    ll rem = c - current;
    rem = k - rem;
    if (rem <= 0)
      return false;
    if (rem >= p)
      return false;
    c++;
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> p;
  f(0, n) cin >> a[i];
  sort(a, a + n);
  ll l = 1, h = 1e9, start = -1, end = -1;
  while (l <= h) {
    ll mid = l + h >> 1;
    if (pos(mid))
      start = mid, h = mid - 1;
    else
      l = mid + 1;
  }
  l = start, h = 1e9;
  while (l <= h) {
    ll mid = l + h >> 1;
    if (check(mid))
      end = mid, l = mid + 1;
    else
      h = mid - 1;
  }
  if (start == -1 || end == -1)
    cout << 0;
  else {
    cout << end - start + 1 << '\n';
    f(start, end + 1) cout << i << ' ';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}