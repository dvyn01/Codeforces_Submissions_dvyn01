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

const ll N = 75;
ll n, k, dp[N][N], taken[N][N];
vector<pair<pair<ll, ll>, ll>> p;
vll v1, v2;

bool compare(pair<pair<ll, ll>, ll> &a, pair<pair<ll, ll>, ll> &b) {
  if (a.first.second != b.first.second)
    return a.first.second < b.first.second;
  return a.first.first < b.first.first;
}

bool compare1(ll a, ll b) { return p[a].first.first < p[b].first.first; }

ll rec(ll in, ll done) {
  if (in == n) {
    if (done == k)
      return 0;
    return -1e18;
  }
  if (dp[in][done] != -1)
    return dp[in][done];
  ll x = (k - 1) * p[in].first.second + rec(in + 1, done);
  taken[in][done] = 0;
  if (done < k) {
    if (done * p[in].first.second + p[in].first.first + rec(in + 1, done + 1) >
        x)
      taken[in][done] = 1,
      x = done * p[in].first.second + p[in].first.first + rec(in + 1, done + 1);
  }
  return dp[in][done] = x;
}

void restore(ll in, ll done) {
  if (in == n)
    return;
  if (taken[in][done] == 1)
    v1.pb(in), restore(in + 1, done + 1);
  else
    v2.pb(in), restore(in + 1, done);
}

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
    cin >> n >> k;
    p.clear();
    p.resize(n);
    f(0, n) cin >> p[i].first.first >> p[i].first.second, p[i].second = i + 1;
    sort(p.begin(), p.end(), compare);
    memset(dp, -1, sizeof(dp));
    v1.clear(), v2.clear();
    rec(0, 0);
    restore(0, 0);
    vll ans;
    sort(v2.begin(), v2.end(), compare1);
    f(0, v1.size() - 1) ans.pb(p[v1[i]].second);
    if (v1.size() == 1)
      ans.pb(p[v1[0]].second);
    if (v1.size() > 1 || (v1.size() == 1 && k > 1))
      f(0, v2.size()) ans.pb(p[v2[i]].second), ans.pb(-p[v2[i]].second);
    if (v1.size() > 1)
      ans.pb(p[v1.back()].second);
    cout << ans.size() << '\n';
    for (auto it : ans)
      cout << it << ' ';
    cout << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}