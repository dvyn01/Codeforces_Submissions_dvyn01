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
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll s[n][m];
    memset(s, 0, sizeof(s));
    ll c[m], r[n];
    memset(c, 0, sizeof(c));
    set<pair<ll, ll>> s1;
    f(0, m) s1.insert({0, i});
    memset(r, 0, sizeof(r));
    bool ok = true;
    f(0, n) {
      ll x = a;
      while (x > 0) {
        auto it = s1.begin();
        if (it->first == b) {
          ok = false;
          break;
        }
        x--;
        pair<ll, ll> p = {it->first + 1, it->second};
        r[i]++;
        c[it->second]++;
        s[i][it->second] = 1;
        s1.erase(s1.begin());
        s1.insert(p);
      }
      if (!ok)
        break;
    }
    f(0, n) {
      if (r[i] != a) {
        ok = false;
        break;
      }
    }
    f(0, m) {
      if (c[i] != b) {
        ok = false;
        break;
      }
    }
    if (!ok)
      cout << "NO\n";
    else {
      cout << "YES\n";
      f(0, n) {
        fi(0, m) cout << s[i][j];
        cout << '\n';
      }
    }
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}