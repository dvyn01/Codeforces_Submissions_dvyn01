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

inline ll mul(ll x, ll y, ll m) {
  ll z = 1LL * x * y;
  if (z >= m)
    z %= m;
  return z;
}
inline ll add(ll x, ll y, ll m) {
  ll z = x + y;
  if (z >= m)
    z %= m;
  return z;
}
inline ll sub(ll x, ll y, ll m) {
  ll z = x - y;
  if (z < 0)
    z += m;
  z %= m;
  return z;
}

const ll N = 1000005;
ll n, m, k, pr[N];
map<pair<ll, ll>, ll> M;

ll powmod(ll x, ll y) {
  ll r = 1;
  while (y) {
    if (y & 1)
      r = mul(r, x, mod);
    y >>= 1;
    x = mul(x, x, mod);
  }
  return r;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bool z = false;
  ll x, y;
  cin >> n >> m >> k;
  f(0, m) cin >> x >> y,
      M[{x, y}] = 1, (((y - x != k + 1) && (y - x != 1)) ? z = true : 0);
  f(1, n + 1) {
    if (M.find({i, i + k + 1}) != M.end())
      pr[i]++;
    pr[i] += pr[i - 1];
  }
  f(1, n + 1) {
    if (pr[i] != 0) {
      if (pr[i + k] != pr[n])
        z = true;
      break;
    }
  }
  if (z) {
    cout << 0;
    return 0;
  }
  ll ans = 1;
  if (pr[n] == 0) {
    f(1, n - k) {
      ll r = i + k;
      if (r > n - k - 1)
        r = n - k - 1;
      ans = add(ans, powmod(2, r - i), mod);
    }
  } else {
    ll last = -1, first = -1;
    f(1, n + 1) {
      if (pr[i] != pr[i - 1]) {
        if (first == -1)
          first = i;
        last = i;
      }
    }
    f(1, n + 1) {
      if (i + k + 1 > last && pr[i] == pr[i - 1] && i + k + 1 <= n &&
          i < first + k + 1) {
        ll r = min(i + k, n - k - 1);
        r = min(r, first + k);
        r = (r - i) + 1 - (pr[r] - pr[i]);
        r--;
        ans = add(ans, powmod(2, r), mod);
      }
    }
  }
  cout << ans << '\n';

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}