#include <bits/stdc++.h>
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
ll pr[N];
pll p;
map<ll, ll> m;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, x;
  cin >> n;
  f(1, n + 1) cin >> x, m[x]++;
  for (auto it : m)
    p.pb({it.second, it.first});
  sort(p.begin(), p.end());
  f(0, p.size()) pr[i + 1] = p[i].first, pr[i + 1] += pr[i];
  ll mx = 0, sz = 0;
  f(1, N) {
    pair<ll, ll> q = {i, 1e18};
    ll k = upper_bound(p.begin(), p.end(), q) - p.begin();
    ll tot = (p.size() - k) * i + pr[k];
    if (tot % i != 0)
      tot -= (tot % i);
    if (tot / i < i)
      continue;
    if (tot > mx)
      mx = tot, sz = i;
  }
  cout << mx << '\n';
  cout << sz << ' ' << mx / sz << '\n';
  reverse(p.begin(), p.end());
  f(0, p.size()) if (p[i].first > sz) p[i].first = sz;
  vector<vector<ll>> ans;
  ans.resize(sz + 1);
  f(0, sz + 1) ans[i].resize(mx / sz + 1);
  pll v;
  ll r = sz, c = mx / sz;
  x = 1;
  while (x + sz - 1 <= c)
    v.pb({1, x}), x++;
  ll l = 1;
  while (x <= c) {
    v.pb({1, x});
    x++;
    v.pb({r - l + 1, 1});
    l++;
  }
  x = 0;
  f(0, v.size()) {
    ll cx = v[i].first, cy = v[i].second;
    while (cx <= r && cy <= c) {
      ans[cx][cy] = p[x].second, cx++, cy++;
      p[x].first--;
      if (p[x].first == 0)
        x++;
    }
  }
  f(1, r + 1) {
    fi(1, c + 1) cout << ans[i][j] << ' ';
    cout << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}