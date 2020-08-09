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

const ll N = 500005;
ll b[N], a[N >> 1], fr[N], vis[N >> 1];
vll v[N >> 1];

void sieve() {
  f(1, N) b[i] = i;
  f(4, N) b[i] = 2, i++;
  f(3, N) {
    if (b[i] == i) {
      for (ll j = i * i; j < N; j += i)
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
  ll n, q;
  cin >> n >> q;
  f(1, n + 1) {
    cin >> a[i];
    while (a[i] > 1) {
      ll x = b[a[i]];
      while (a[i] % x == 0)
        a[i] /= x;
      v[i].pb(x);
    }
  }
  ll ans = 0, tot = 0;
  while (q--) {
    ll in;
    cin >> in;
    if (vis[in])
      tot--;
    else
      tot++;
    if (vis[in]) {
      f(0, 1LL << v[in].size()) {
        ll p = 1;
        fi(0, v[in].size()) if (i & (1LL << j)) p *= v[in][j];
        if (p != 1)
          fr[p]--;
      }
    }
    f(0, 1LL << v[in].size()) {
      ll x = 0, p = 1;
      fi(0, v[in].size()) if (i & (1LL << j)) p *= v[in][j], x ^= 1;
      if (x) {
        if (!vis[in])
          ans += fr[p];
        else
          ans -= fr[p];
      } else {
        if (!vis[in])
          ans -= fr[p];
        else
          ans += fr[p];
      }
    }
    if (!vis[in]) {
      f(0, 1LL << v[in].size()) {
        ll p = 1;
        fi(0, v[in].size()) if (i & (1LL << j)) p *= v[in][j];
        if (p != 1)
          fr[p]++;
      }
    }
    vis[in] ^= 1;
    cout << (tot * (tot - 1)) / 2 - ans << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}