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

const ll N = 505;
ll a[N], b[N];

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
    ll n;
    cin >> n;
    f(1, n + 1) cin >> a[i];
    f(1, n + 1) cin >> b[i];
    if (n & 1) {
      ll k = (n >> 1) + 1;
      if (a[k] != b[k]) {
        cout << "No\n";
        continue;
      }
    }
    bool ok = true;
    map<pair<ll, ll>, ll> m1;
    ll k = n >> 1;
    if (n & 1)
      k++;
    ll lp = 1, rp = n;
    while (lp < rp) {
      m1[{min(a[lp], a[rp]), max(a[lp], a[rp])}]++;
      lp++;
      rp--;
    }
    lp = 1, rp = n;
    while (lp < rp) {
      if (m1.find({min(b[lp], b[rp]), max(b[lp], b[rp])}) == m1.end()) {
        ok = false;
        break;
      }
      m1[{min(b[lp], b[rp]), max(b[lp], b[rp])}]--;
      if (m1[{min(b[lp], b[rp]), max(b[lp], b[rp])}] == 0)
        m1.erase(m1.find({min(b[lp], b[rp]), max(b[lp], b[rp])}));
      lp++;
      rp--;
    }
    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}