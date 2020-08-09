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
ll a[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  map<ll, ll> m;
  f(1, n + 1) cin >> a[i], m[a[i]]++;
  set<pair<ll, ll>> s;
  for (auto it : m)
    s.insert({it.second, it.first});
  ll q;
  cin >> q;
  while (q--) {
    char c;
    ll x;
    cin >> c >> x;
    if (c == '-') {
      auto it = s.find({m[x], x});
      s.erase(it);
      m[x]--;
      if (m[x] == 0)
        m.erase(m.find(x));
      else
        s.insert({m[x], x});
    } else {
      if (m.find(x) == m.end()) {
        m[x] = 1;
        s.insert({1, x});
      } else {
        s.erase(s.find({m[x], x}));
        m[x]++;
        s.insert({m[x], x});
      }
    }
    if (s.empty()) {
      cout << "NO\n";
      continue;
    }
    auto it = --(s.end());
    if (it->first < 4) {
      cout << "NO\n";
      continue;
    }
    ll rem = it->first - 4;
    if (rem >= 4) {
      cout << "YES\n";
      continue;
    }
    if (rem >= 2) {
      if (s.size() == 1) {
        cout << "NO\n";
        continue;
      }
      it--;
      pair<ll, ll> p1 = *it;
      if (p1.first >= 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      if (s.size() == 1) {
        cout << "NO\n";
        continue;
      }
      it--;
      if (it->first >= 4) {
        cout << "YES\n";
        continue;
      }
      if (it->first < 2 || s.size() < 3) {
        cout << "NO\n";
        continue;
      }
      it--;
      if (it->first >= 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}