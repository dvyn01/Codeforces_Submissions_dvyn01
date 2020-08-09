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

  ll n, x, y;
  cin >> n >> x >> y;
  pll p;
  p.resize(n);
  f(0, n) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());
  ll ans = 0, last = 0;
  multiset<ll> s, s1;
  f(0, n) {
    s.insert(p[i].second);
    while (!s.empty() && *s.begin() < p[i].first)
      s1.insert(*s.begin()), s.erase(s.begin());
    auto it = s1.lower_bound(p[i].first);
    ll pr = -1e9;
    if (it != s1.begin()) {
      it--;
      pr = *it;
    }
    if ((p[i].second - pr) * y < x + (p[i].second - p[i].first) * y)
      ans = last + (p[i].second - pr) * y, s1.erase(it);
    else
      ans = last + x + (p[i].second - p[i].first) * y;
    if (ans > mod)
      ans %= mod;
    last = ans;
  }
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}