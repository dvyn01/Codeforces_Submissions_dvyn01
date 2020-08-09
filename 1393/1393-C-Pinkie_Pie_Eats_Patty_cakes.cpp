#include <bits/stdc++.h>
/** #include <ext/pb_ds/assoc_container.hpp>
 * #include <ext/pb_ds/tree_policy.hpp>
 * using namespace __gnu_pbds; */
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
/** typedef tree<ll
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
ll n, a[N], fr[N];
vll v[N];

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
    cin >> n;
    f(1, n + 1) fr[i] = 0, v[i].clear();
    f(1, n + 1) cin >> a[i], fr[a[i]]++;
    set<pair<ll, ll>> s;
    f(1, n + 1) {
      if (fr[i] > 0)
        s.insert({-fr[i], i});
    }
    ll mx = abs(s.begin()->first);
    f(1, mx + 1) v[i].pb(s.begin()->second);
    ll cp = 1;
    s.erase(s.begin());
    while (!s.empty()) {
      ll k = abs(s.begin()->first);
      ll elem = s.begin()->second;
      s.erase(s.begin());
      if (k == mx) {
        while (k--) {
          v[cp].pb(elem);
          cp++;
          if (cp == mx + 1)
            cp = 1;
        }
      } else {
        while (k--) {
          v[cp].pb(elem);
          cp++;
          if (cp == mx)
            cp = 1;
        }
      }
    }
    if (mx == 1) {
      cout << 0 << '\n';
      continue;
    }
    cout << v[mx - 1].size() - 1 << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}