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
ll a[N];
map<ll, vll> m;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  f(1, n + 1) {
    cin >> a[i];
    for (ll j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        ll c = 0;
        while (a[i] % j == 0)
          c++, a[i] /= j;
        if (m.find(j) == m.end())
          m[j];
        m[j].pb(c);
      }
    }
    if (a[i] > 1) {
      if (m.find(a[i]) == m.end())
        m[a[i]];
      m[a[i]].pb(1);
    }
  }
  ll ans = 1;
  for (auto it : m) {
    if (it.second.size() == n) {
      vll v = it.second;
      sort(v.begin(), v.end());
      ans *= pow(it.first, v[1]);
    } else if (it.second.size() == n - 1) {
      vll v = it.second;
      sort(v.begin(), v.end());
      ans *= pow(it.first, v[0]);
    }
  }
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}