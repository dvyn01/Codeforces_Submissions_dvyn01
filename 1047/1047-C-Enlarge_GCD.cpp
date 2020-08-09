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

const ll N = 300005;
ll x, g, b[15000001], mx[15000001];
map<pair<ll, ll>, ll> m;

void sieve() {
  f(1, 15000001) b[i] = i;
  f(2, 15000001) b[i] = 2, i++;
  for (int i = 3; i * i < 15000001; i++) {
    if (b[i] == i) {
      for (int j = i * i; j < 15000001; j += i)
        if (b[j] == j)
          b[j] = i;
    }
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
  ll n, p = 0;
  cin >> n;
  f(1, n + 1) {
    cin >> x;
    if (x == 1)
      p++;
    if (x != 1)
      g = __gcd(x, g);
    while (x != 1) {
      ll k = b[x], c = 0;
      while (x % k == 0)
        c++, x /= k, m[{k, c}]++;
    }
  }
  if (p != 0 && p < n && g != 1) {
    cout << p;
    return 0;
  }
  ll ans = 1e18;
  while (g != 1 && g != 0) {
    ll k = b[g], c = 0;
    while (g % k == 0)
      c++, g /= k;
    mx[k] = c;
  }
  for (auto it : m) {
    if (mx[it.first.first] >= it.first.second)
      continue;
    ans = min(ans, n - p - it.second);
  }
  ans += p;
  if (ans >= 1e18)
    ans = -1;
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}