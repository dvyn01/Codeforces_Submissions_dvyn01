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
template <class L, class R> ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R> ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M)
    os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}

const ll N = 100005;

char calc(ll x1, ll y1, ll x2, ll y2) {
  if (x1 == x2) {
    if (y2 > y1)
      return 'U';
    return 'D';
  } else {
    if (x2 > x1)
      return 'R';
    return 'L';
  }
  return '$';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  pll p;
  p.resize(n);
  string s;
  f(0, n) {
    cin >> p[i].first >> p[i].second;
    if (i == 0)
      continue;
    s.pb(calc(p[i - 1].first, p[i - 1].second, p[i].first, p[i].second));
  }
  ll ans = 0;
  f(0, s.length() - 1) {
    if (s[i] == 'R' && s[i + 1] == 'U')
      ans++;
    else if (s[i] == 'U' && s[i + 1] == 'L')
      ans++;
    else if (s[i] == 'L' && s[i + 1] == 'D')
      ans++;
    else if (s[i] == 'D' && s[i + 1] == 'R')
      ans++;
  }
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}