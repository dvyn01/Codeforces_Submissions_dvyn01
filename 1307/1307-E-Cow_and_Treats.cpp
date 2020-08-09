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

inline ll mul(ll x, ll y, ll m) {
  x %= mod;
  y %= mod;
  long long z = 1LL * x * y;
  if (z >= m)
    z %= m;
  return z;
}
inline ll add(ll x, ll y, ll m) {
  long long z = x + y;
  if (z >= m)
    z %= m;
  return z;
}
inline ll sub(ll x, ll y, ll m) {
  long long z = x - y;
  if (z < 0)
    z += m;
  z %= m;
  return z;
}

const ll N = 5005;
ll n, m, a[N], f[N], h[N], tot[N], pr[N][N], su[N][N];
vll v[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  f(1, n + 1) cin >> a[i], tot[a[i]]++, pr[a[i]][i]++;
  f(1, n + 1) fi(1, n + 1) pr[i][j] += pr[i][j - 1],
      su[i][j] = tot[i] - pr[i][j];
  f(1, m + 1) {
    ll f, h;
    cin >> f >> h;
    v[f].pb(h);
  }
  f(1, n + 1) sort(v[i].begin(), v[i].end());
  ll ans = 0, ways = 1;
  f(1, n + 1) {
    ll l = pr[a[i]][i];
    ll l1 = lower_bound(v[a[i]].begin(), v[a[i]].end(), l) - v[a[i]].begin();
    if (l1 == v[a[i]].size() || l != v[a[i]][l1])
      continue;
    ll c = 0, w = 1;
    fi(1, n + 1) {
      if (j == a[i]) {
        ll k = su[j][i];
        ll k1 = upper_bound(v[j].begin(), v[j].end(), k) - v[j].begin() - 1;
        if (k1 != -1) {
          if (k1 == 0 && v[j][k1] == l) {
            c++;
            continue;
          }
          c += 2;
          if (v[j][k1] >= l)
            w = mul(w, k1, mod);
          else
            w = mul(w, (k1 + 1), mod);
          w %= mod;
        } else {
          c++;
        }
      } else {
        ll k1 = upper_bound(v[j].begin(), v[j].end(), pr[j][i]) - v[j].begin();
        ll k2 = upper_bound(v[j].begin(), v[j].end(), su[j][i]) - v[j].begin();
        if (k1 != 0 && k2 != 0) {
          if (k1 == k2 && k1 == 1)
            c++, w = mul(w, 2, mod);
          else
            c += 2, w = mul(w, sub(mul(k1, k2, mod), min(k1, k2), mod), mod);
          if (w < 0)
            w += mod;
          w %= mod;
        } else if (k1 == 0 && k2 == 0) {
          continue;
        } else {
          c++;
          if (k1 != 0)
            w = mul(w, k1, mod);
          else
            w = mul(w, k2, mod);
          w %= mod;
        }
        if (w < 0)
          w += mod;
      }
      if (w < 0)
        w += mod;
    }
    if (c > ans)
      ans = c, ways = w;
    else if (c == ans)
      ways = add(ways, w, mod);
  }
  ll c = 0, w = 1;
  f(1, n + 1) {
    if (v[i].size() > 0) {
      ll k = upper_bound(v[i].begin(), v[i].end(), tot[i]) - v[i].begin();
      if (k != 0)
        c++, w = mul(w, k, mod);
      w %= mod;
    }
  }
  if (c == ans && c != 0)
    ways = add(ways, w, mod);
  cout << ans << ' ' << ways << '\n';

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}