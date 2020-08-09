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

const ll N = 200005;
ll dp[2005], fact[N], inv[N];
pll p;

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

void pre() {
  fact[0] = 1, inv[0] = 1;
  f(1, N) fact[i] = mul(i, fact[i - 1], mod), inv[i] = powmod(fact[i], mod - 2);
}

ll ncr(ll n, ll r) {
  if (r > n)
    return 0;
  return mul(fact[n], mul(inv[r], inv[n - r], mod), mod);
}

ll ways(ll x, ll y) { return ncr(x + y - 2, x - 1); }

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre();
  ll h, w, n;
  cin >> h >> w >> n;
  p.resize(n + 1);
  f(0, n) cin >> p[i].first >> p[i].second;
  p[n].first = h, p[n].second = w;
  sort(p.begin(), p.end());
  f(0, n + 1) {
    dp[i] = ways(p[i].first, p[i].second);
    fi(0, i) {
      if (p[j].second <= p[i].second) {
        dp[i] = sub(dp[i],
                    mul(dp[j],
                        ways(p[i].first - p[j].first + 1,
                             p[i].second - p[j].second + 1),
                        mod),
                    mod);
      }
    }
  }
  cout << dp[n];

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}