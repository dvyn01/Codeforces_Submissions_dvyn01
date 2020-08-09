#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

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
ll s[N], n, m;
pll p;

ll find(ll v) {
  ll l = 0, h = m - 1, ans = -1;
  while (l <= h) {
    ll mid = l + h >> 1;
    if (p[mid].first >= v)
      ans = mid, l = mid + 1;
    else
      h = mid - 1;
  }
  return ans;
}

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
    ll ans = 0;
    cin >> n >> m;
    p.clear();
    p.resize(m);
    f(0, m) cin >> p[i].first >> p[i].second, s[i] = 0;
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    s[0] = p[0].first;
    f(1, m) s[i] = s[i - 1] + p[i].first;
    if (n <= m)
      ans = max(ans, s[n - 1]);
    f(0, m) {
      ll x = find(p[i].second);
      if (x == -1) {
        ans = max(ans, p[i].first + (n - 1) * p[i].second);
        continue;
      }
      if (x >= i) {
        ll rem = n - x - 1;
        if (rem >= 0)
          ans = max(ans, s[x] + rem * p[i].second);
      } else {
        ll rem = n - x - 2;
        if (rem >= 0)
          ans = max(ans, s[x] + p[i].first + rem * p[i].second);
      }
    }
    cout << ans << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}