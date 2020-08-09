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

const ll N = 100005;
ll n, b[N], dp[N];
pll p;
vll v;

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

void sieve() {
  f(1, N) b[i] = i;
  f(4, N) b[i] = 2, i++;
  f(3, N) {
    if (b[i] == i) {
      for (ll j = i * i; j < N; j += i)
        if (b[j] = j)
          b[j] = i;
    }
  }
}

void getFactors(ll in, ll c) {
  if (in >= p.size())
    return;
  f(0, p[in].second + 1) {
    getFactors(in + 1, c);
    c *= p[in].first;
    if (i != p[in].second)
      v.pb(c);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();
  cin >> n;
  ll inv = powmod(n, mod - 2);
  dp[1] = 0;
  f(2, n + 1) {
    dp[i] = 1;
    ll k = i;
    p.clear();
    while (k > 1) {
      ll x = b[k], c = 0;
      while (k % x == 0)
        c++, k /= x;
      p.pb({x, c});
    }
    v.clear();
    v.pb(1);
    getFactors(0, 1);
    fi(0, v.size()) {
      if (v[j] == i)
        continue;
      ll x = i / v[j], lim = n / v[j];
      vll cur;
      while (x != 1) {
        ll y = b[x];
        cur.pb(y);
        while (x % y == 0)
          x /= y;
      }
      ll tot = 0;
      fi(1, 1LL << cur.size()) {
        ll x = 0, p1 = 1;
        fii(0, cur.size()) if ((1LL << k) & j) x ^= 1, p1 *= cur[k];
        if (x)
          tot += lim / p1;
        else
          tot -= lim / p1;
      }
      tot = lim - tot;
      dp[i] = add(dp[i], mul(dp[v[j]], mul(tot, inv, mod), mod), mod);
    }
    ll p = n / i;
    p = mul(p, inv, mod);
    p = sub(1, p, mod);
    p = powmod(p, mod - 2);
    dp[i] = mul(dp[i], p, mod);
  }
  ll ans = 1;
  f(1, n + 1) ans = add(ans, mul(dp[i], inv, mod), mod);
  cout << ans << '\n';

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}