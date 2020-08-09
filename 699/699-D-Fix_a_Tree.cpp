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

const ll N = 200005;
ll p[N], a[N], s[N];

void init(ll n) { f(1, n + 1) a[i] = i, s[i] = 1; }

ll roott(ll i) {
  while (i != a[i])
    i = a[a[i]];
  return i;
}

void merge(ll x, ll y) {
  ll xr = roott(x), yr = roott(y);
  if (xr == yr)
    return;
  if (s[yr] > s[xr])
    swap(xr, yr);
  s[xr] += s[yr];
  a[yr] = xr;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, tot = 0;
  cin >> n;
  init(n);
  f(1, n + 1) cin >> p[i];
  f(1, n + 1) if (p[i] != i) merge(i, p[i]);
  ll root = -1;
  f(1, n + 1) {
    if (p[i] == i) {
      if (root == -1)
        root = i;
      else
        merge(root, i), tot++, p[i] = root;
    }
  }
  f(1, n + 1) {
    if (root == -1 || roott(i) != roott(root)) {
      ll c = i;
      map<ll, ll> m;
      m[c] = 1;
      while (m.find(p[c]) == m.end())
        c = p[c], m[c] = 1;
      tot++;
      if (root == -1)
        p[c] = c, root = c;
      else
        p[c] = root, merge(root, c);
    }
  }
  cout << tot << '\n';
  f(1, n + 1) cout << p[i] << ' ';

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}