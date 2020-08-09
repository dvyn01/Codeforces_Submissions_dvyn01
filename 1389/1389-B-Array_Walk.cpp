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
ll a[N], mx[N], s[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll n, k, z;
    cin >> n >> k >> z;
    s[0] = 0;
    f(1, n + 1) cin >> a[i], s[i] = a[i], s[i] += s[i - 1];
    mx[2] = a[1] + a[2];
    f(3, n + 1) mx[i] = max(mx[i - 1], a[i - 1] + a[i]);
    ll ans = s[k + 1];
    if (k > 0 && z > 0)
      ans = max(ans, s[k] + a[k - 1]);
    ll p = k + 1, c = 0;
    ll z1 = z;
    while (p > 0 && z > 0) {
      z--;
      p -= 2;
      c++;
      ll y = s[p];
      y += mx[p] * c;
      ans = max(ans, y);
      y = 0;
      y += s[p + 1];
      ll rem = k - p;
      ll kr = z1;
      while (rem > 0 && kr > 0) {
        if (rem > 2)
          y += a[p] + a[p + 1];
        else
          y += a[p];
        kr--;
        rem -= 2;
        // cout << y << " -- ";
      }
      // cout << p + 1 << ' ' << y << '\n';
      ans = max(ans, y);
    }
    cout << ans << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}