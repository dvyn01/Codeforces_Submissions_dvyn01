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

const ll N = 400005;
ll a[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, h, m, k;
  cin >> n >> h >> m >> k;
  pll p;
  f(0, n) {
    ll a, b;
    cin >> a >> b;
    p.pb({i, a * m + b});
  }
  pll intervals;
  f(0, n) {
    ll k1 = 2 * p[i].second / m;
    k1 = p[i].second - k1 * m / 2;
    intervals.pb({k1 + 1, k1 + k});
    k1 -= m / 2;
    intervals.pb({k1 + 1, k1 + k});
  }
  map<ll, ll> m1;
  f(0, intervals.size()) m1[intervals[i].first]++, m1[intervals[i].second]++;
  ll c = 1;
  map<ll, ll> rev;
  for (auto it : m1)
    m1[it.first] = c++, rev[c - 1] = it.first;
  f(0, intervals.size()) a[m1[intervals[i].first]]++,
      a[m1[intervals[i].second]]--;
  f(1, c) a[i] += a[i - 1];
  ll mn = 1e18, ans = -1;
  f(1, c - 1) {
    if (a[i] < mn && rev[i] >= 0 && rev[i] <= m / 2) {
      mn = a[i];
      ans = rev[i];
    }
  }
  ll k1 = 2 * ans / m;
  ans = ans - k1 * m / 2;
  vll missed;
  f(0, n) {
    ll k1 = 2 * p[i].second / m;
    k1 = p[i].second - k1 * m / 2;
    ll l = k1 + 1, r = k1 + k;
    if (l <= ans && r > ans)
      missed.pb(i + 1);
    else {
      k1 -= m / 2;
      l = k1 + 1, r = k1 + k;
      if (l <= ans && r > ans)
        missed.pb(i + 1);
    }
  }
  cout << missed.size() << ' ' << ans << '\n';
  f(0, missed.size()) cout << missed[i] << ' ';

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}