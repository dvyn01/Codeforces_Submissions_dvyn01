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
ll fr[N], b[N], dp[N];
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
  ll n;
  cin >> n;
  f(1, n + 1) {
    p.clear();
    ll x;
    cin >> x;
    while (x > 1) {
      ll y = b[x], c = 0;
      while (x % y == 0)
        x /= y, c++;
      p.pb({y, c});
    }
    v.clear();
    getFactors(0, 1);
    fi(0, v.size()) fr[v[j]]++;
  }
  ll ans = 0;
  fr(N - 5, 2) {
    if (fr[j] > 0) {
      ll x = mul(fr[j], powmod(2, fr[j] - 1), mod);
      dp[j] = x;
      f(j << 1, N) {
        if (fr[i] != 0)
          dp[j] = sub(dp[j], dp[i], mod);
        i += j - 1;
      }
      ans = add(ans, mul(j, dp[j], mod), mod);
    }
  }
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}