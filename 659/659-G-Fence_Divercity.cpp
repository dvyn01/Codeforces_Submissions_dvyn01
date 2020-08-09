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
ll n, a[N], dp[N][2];

ll rec(ll in, ll s) {
  if (dp[in][s] != -1)
    return dp[in][s];
  ll k = 0;
  if (s == 0) {
    if (a[in + 1] != 0)
      k = add(k, rec(in + 1, s), mod);
    else
      k = add(k, a[in] - 1, mod);
    if (a[in + 1] != 0 && a[in] > a[in + 1])
      k = add(k, a[in] - a[in + 1], mod);
    if (a[in + 1] != 0)
      k = add(k, mul(min(a[in], a[in + 1]) - 1, rec(in + 1, 1), mod), mod);
  } else {
    if (a[in + 1] == 0)
      k = add(k, min(a[in], a[in - 1]), mod);
    else {
      ll mn = min(a[in - 1], min(a[in], a[in + 1]));
      k = add(k, mul(mn - 1, rec(in + 1, s), mod), mod);
      if (a[in + 1] < a[in] && a[in + 1] < a[in - 1])
        k = add(k, min(a[in], a[in - 1]) - a[in + 1], mod);
      k = add(k, 1, mod);
    }
  }
  return dp[in][s] = k;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  f(1, n + 1) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  ll ans = rec(1, 0);
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}