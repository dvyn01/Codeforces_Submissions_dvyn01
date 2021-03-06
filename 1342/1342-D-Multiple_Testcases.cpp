#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll int
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
template <class T> ostream &operator<<(ostream &os, multiset<T> S) {
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

const ll N = 200005;
ll c[N], jump[N];
multiset<ll> s;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k, x;
  cin >> n >> k;
  f(1, n + 1) cin >> x, s.insert(x);
  f(1, k + 1) cin >> c[i];
  f(1, k + 1) {
    ll j = i;
    while (j <= k && c[j] == c[i])
      jump[j] = i, j++;
    i = j - 1;
  }
  vector<vector<ll>> ans;
  while (s.size() > 0) {
    vll v;
    ll cs = 0;
    fr(k, 1) {
      if (s.empty())
        break;
      if (*(--s.end()) < j) {
        j = *(--s.end()) + 1;
        continue;
      }
      if (cs >= c[j]) {
        j = jump[j];
        continue;
      }
      bool ok = true;
      ll x = c[j], lim = 1e9;
      if (j != k)
        lim = j + 1;
      while (!s.empty() && cs < x) {
        auto it = s.lower_bound(lim);
        if (it == s.begin()) {
          ok = false;
          break;
        }
        cs++;
        it--;
        v.pb(*it);
        s.erase(it);
      }
      if (!ok)
        break;
      j = jump[j];
    }
    ans.pb(v);
  }
  cout << ans.size() << '\n';
  f(0, ans.size()) {
    cout << ans[i].size() << ' ';
    fi(0, ans[i].size()) cout << ans[i][j] << ' ';
    cout << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}