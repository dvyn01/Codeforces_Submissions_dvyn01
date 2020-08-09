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

const ll N = 1005;
ll a[N], n, k;
bool in[N];
pair<ll, ll> t[N];

ll calc(ll x) {
  double c = 100.0 * x / n * 1.0;
  ll k = c;
  if (c - k < 0.5)
    return k;
  return k + 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  f(1, n + 1) cin >> a[i];
  ll done = 0, cp = 1;
  set<ll> vac;
  f(1, k + 1) vac.insert(i);
  while (done < n) {
    while (!vac.empty() && cp <= n)
      t[*vac.begin()] = {1, cp}, cp++, vac.erase(vac.begin());
    ll aux = 0;
    f(1, k + 1) {
      if (t[i].first != 0) {
        if (calc(done) == t[i].first)
          in[t[i].second] = true;
        t[i].first++;
        if (t[i].first > a[t[i].second]) {
          aux++;
          t[i] = {0, 0};
          vac.insert(i);
        }
      }
    }
    done += aux;
  }
  ll ans = 0;
  f(1, n + 1) if (in[i]) ans++;
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}